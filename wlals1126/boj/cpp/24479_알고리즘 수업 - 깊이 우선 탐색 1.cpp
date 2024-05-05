#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, cnt;
vector<bool> visited;
vector<int> answer;
vector<vector<int>> graph;

void dfs(int x) {
    visited[x] = true;
    answer[x] = ++cnt;

    for (int i : graph[x]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    visited.resize(N + 1, false);
    graph.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        graph[i].reserve(101);
    }

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited[R] = true;
    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
