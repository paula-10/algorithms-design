#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// funcție pentru a găsi sortarea topologică a grafului
// luata din solutiile publicate
vector<string> topologicalSort(
    unordered_map<string, vector<string>>& graph,
    unordered_map<string, int>& in_degree) {

    vector<string> topo_order;
    queue<string> q;

    for (const auto& pair : graph) {
        const string& node = pair.first;
        if (in_degree[node] == 0) {
            q.push(node);
        }
    }

    while (!q.empty()) {
        string node = q.front();
        q.pop();
        topo_order.push_back(node);

        for (auto& neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return topo_order;
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");
    int m;
    string source, destination;
    // se citesc datele din fisierul de intrare
    fin >> source;
    fin >> destination;
    fin >> m;

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> in_degree;

    // se citesc muchiile si se construieste graful
    for (int i = 0; i < m; ++i) {
        string x, y;
        fin >> x >> y;
        // se adauga nodul y la lista de vecini a nodului x
        graph[x].push_back(y);
        in_degree[y]++;
        if (in_degree.find(x) == in_degree.end()) {
            in_degree[x] = 0;
        }
    }

    // este ordonat graful in ordine topologica
    vector<string> topo_order = topologicalSort(graph, in_degree);
    unordered_map<string, int> distance;
    // initializara distanta la fiecare nod cu o valoarea negativa
    for (const auto& node : topo_order) {
        distance[node] = INT_MIN;
    }
    // seteaza distanta la nodul sursa ca fiind 1
    distance[source] = 1;

    // se itereaza prin toate nodurile in ordine topologica
    for (const auto& node : topo_order) {
        // se verifica daca nodul este accesibil din sursa
        if (distance[node] != INT_MIN) {
            // se itereaza prin vecinii nodului curent
            for (const auto& neighbor : graph[node]) {
                // se verifica daca distanta la vecinul curent poate fi marita
                // in caz afirmativ, se actualizeaza
                if (distance[neighbor] < distance[node] + 1) {
                    distance[neighbor] = distance[node] + 1;
                }
            }
        }
    }

    fout << distance[destination] << endl;

    fin.close();
    fout.close();
    return 0;
}
