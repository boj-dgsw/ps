#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int C, R, K;
    cin >> C >> R >> K;

    if (K > C * R) {
        cout << 0 << endl;
        return 0;
    }

    int x = 1, y = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dir = 0;
    vector<vector<bool>> visited(C + 1, vector<bool>(R + 1, false));

    for (int i = 1; i <= C * R; ++i) {
        if (i == K) {
            cout << x << ' ' << y << endl;
            return 0;
        }
        
        visited[x][y] = true;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx <= 0 || nx > C || ny <= 0 || ny > R || visited[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        x = nx;
        y = ny;
    }

    return 0;
}
