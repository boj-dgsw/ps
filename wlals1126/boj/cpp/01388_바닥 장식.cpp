#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> arr;
vector<vector<bool>> visited;

void search(int x, int y) {
    if (arr[x][y] == '-') {
        if (y + 1 < m && arr[x][y + 1] == '-' && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            search(x, y + 1);
        }
    }
    if (arr[x][y] == '|') {
        if (x + 1 < n && arr[x + 1][y] == '|' && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            search(x + 1, y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                ++result;
                search(i, j);
            }
        }
    }

    cout << result << endl;
    return 0;
}
