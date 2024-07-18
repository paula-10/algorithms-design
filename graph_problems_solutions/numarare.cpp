#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// funcție pentru a găsi sortarea topologică a grafului
// luata din solutiile publicate
vector<int> topologicalSort(int n, const vector<vector<int>>& graph) {
    vector<int> in_degree(n + 1, 0);
    queue<int> q;
    vector<int> topo_order;

    for (int u = 1; u <= n; ++u) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);
        for (int neighbor : graph[node]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return topo_order;
}

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph1(n + 1), graph2(n + 1);

    // se construiesc cele doua grafuri
    for (int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        graph1[x].push_back(y);
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        graph2[x].push_back(y);
    }

    // se sorteaza grafurile topologic
    vector<int> topo_order1 = topologicalSort(n, graph1);
    vector<int> topo_order2 = topologicalSort(n, graph2);

    // vectorul dp stocheaza distantele de la nodul 1 celelalte noduri
    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    // se parcurg nodurile in ordinea sortarii topologice
    for (int node : topo_order1) {
        // se parcurg vecinii nodului curent
        for (int neighbor : graph1[node]) {
            // se verifica existenta unei muchii de la nodul curent la vecin
            for (int n : graph2[node]) {
                if (n == neighbor) {
                    dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
                }
            }
        }
    }

    fout << dp[n] << endl;

    fin.close();
    fout.close();

    return 0;
}
