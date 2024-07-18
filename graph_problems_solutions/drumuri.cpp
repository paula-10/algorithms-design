#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

// este folosita o structura pentru a stoca si vectorul de parinti
struct DijkstraResult {
    vector<long long> distances;
    vector<int> parents;
};

DijkstraResult dijkstra(int source, int nodes, vector<pair<int, int>> adj[]) {
    vector<long long> d(nodes + 1, INF);
    vector<int> p(nodes + 1, source);

    set<pair<long long, int>> pq;

    // se insereaza nodul sursa in coada si se actualizeaza distanta
    d[source] = 0;
    pq.insert({0, source});

    while (!pq.empty()) {
        // se obtine topu-ul
        auto top = pq.begin();
        int node = top->second;
        pq.erase(top);

        // se parcurg vecinii nodului extras
        for (const auto& neighbor : adj[node]) {
            int neigh = neighbor.first;
            long long weight = neighbor.second;

            // se verifica daca distanta se imbunatateste
            if (d[node] + weight < d[neigh]) {
                // daca a fost gasita o distanta mai mica,
                // se elimina distanta veche din set
                pq.erase({d[neigh], neigh});

                // se actualizeaza distanta si parintele
                d[neigh] = d[node] + weight;
                p[neigh] = node;

                // este inserata noua distanta in set
                pq.insert({d[neigh], neigh});
            }
        }
    }

    // toate nodurile catre care distanta este inca INF nu pot fi atinse din
    // nodul source, deci sunt setate pe -1.
    for (int i = 1; i <= nodes; ++i) {
        if (d[i] == INF) {
            d[i] = -1;
        }
    }

    return {d, p};
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    // se citesc numarul de noduri si numarul de muchii din graf
    int n, m;
    fin >> n >> m;

    vector<pair<int, int>> graph[n + 1];
    vector<pair<int, int>> inverted_graph[n + 1];

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        fin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        inverted_graph[b].emplace_back(a, c);
    }

    int x, y, z;
    fin >> x >> y >> z;

    /* 
    -> cu ajutorul functiei dijkstra se obtin distantele minime de la nodul x,
    respectiv nodul y, la toate celelalte noduri
    ->  de asemenea, este aplicata functia pe graful inversat pentru a obtine
    cea mai mica distanta de la nodul z la toate celelalte noduri
    */

    vector<long long> dist_x = dijkstra(x, n, graph).distances;
    vector<long long> dist_y = dijkstra(y, n, graph).distances;
    vector<long long> dist_z = dijkstra(z, n, inverted_graph).distances;

    /*
    ->  se cauta nodul care are suma distantei de la x, distantei de la y si
    distantei de la z cea mai mica si se afiseaza aceasta suma */
    long long min_cost = LLONG_MAX;
    for (int node = 1; node <= n; ++node) {
        // verifica daca nodul este accesibil din toate cele 3 noduri
        if (dist_x[node] != -1 && dist_y[node] != -1 && dist_z[node] != -1) {
            long long cost = dist_x[node] + dist_y[node] + dist_z[node];
            min_cost = min(min_cost, cost);
        }
    }

    fout << min_cost << endl;

    fin.close();
    fout.close();

    return 0;
}
