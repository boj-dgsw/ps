#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    int num = 1;
    int l = 0;
    int x = n / 2;
    int y = n / 2;
    graph[x][y] = 1;
    pair<int, int> answer = make_pair(x, y);

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (true) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < l; ++j) {
                x += dx[i];
                y += dy[i];
                num += 1;
                graph[x][y] = num;
                if (num == m) answer = make_pair(x + 1, y + 1);
            }
        }

        if (x == 0 && y == 0) break;

        x -= 1;
        y -= 1;
        l += 2;
    }

    int mx = 0, my = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << ' ';
            if (graph[i][j] == m) {
                mx = i + 1;
                my = j + 1;
            }
        }
        cout << '\n';
    }
    cout << mx << ' ' << my << '\n';

    return 0;
}
