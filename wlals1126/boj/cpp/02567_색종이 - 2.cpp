#include <iostream>
#include <vector>

using namespace std;

int main() {
    int map[101][101] = {0}; 
    int n;
    cin >> n;
    int length = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int r = x; r < x + 10; ++r) {
            for (int c = y; c < y + 10; ++c) {
                map[r][c] = 1;
            }
        }
    }

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (map[i][j] == 1) {
                for (int d = 0; d < 4; ++d) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (map[nx][ny] == 0) ++length;
                }
            }
        }
    }

    cout << length << endl;

    return 0;
}
