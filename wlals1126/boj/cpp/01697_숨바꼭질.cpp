#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> visited(100001);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) next = x + 1;
            else if (i == 1) next = x - 1;
            else next = x * 2;

            if (next == M) {
                cout << visited[x] << endl;
                return;
            }

            if (next >= 0 && next < visited.size() && visited[next] == 0) {
                q.push(next);
                visited[next] = visited[x] + 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    if (N == M) {
        cout << 0 << endl;
    } else {
        bfs(N);
    }

    return 0;
}
