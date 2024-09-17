#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; 
vector<int> depth;         

void dfs(int node) {
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (depth[next] == -1) {  
            depth[next] = depth[node] + 1;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    r--;  

    graph.resize(n);
    depth.assign(n, -1);  

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    depth[r] = 0;
    dfs(r);

    for (int i = 0; i < n; i++) {
        cout << depth[i] << '\n';
    }

    return 0;
}
