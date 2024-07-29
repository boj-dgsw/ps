#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, result;
vector<vector<bool>> nums;
vector<bool> visited;

void count(int cnt) {
    queue<int> q;
    q.push(cnt);
    visited[cnt] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (nums[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    nums.resize(N + 1, vector<bool>(N + 1, false));
    visited.resize(N + 1, false);
    result = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        nums[u][v] = nums[v][u] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count(i);
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
