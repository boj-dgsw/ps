#include <iostream>
#include <queue>
using namespace std;

struct Pair {
    int x;
    int y;
    int count;

    Pair(int _x, int _y, int _count) : x(_x), y(_y), count(_count) {}
};

int map[20][20];
int dir[4][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int counting;

void bfs(int x, int y, int d) {
    queue<Pair> q;
    q.push(Pair(x, y, 1));

    counting = 0;

    while (!q.empty()) {
        Pair p = q.front();
        q.pop();
        counting = max(p.count, counting);

        int dx = p.x + dir[d][0];
        int dy = p.y + dir[d][1];

        if (dx >= 0 && dx < 19 && dy >= 0 && dy < 19 && map[dx][dy] == map[p.x][p.y]) {
            q.push(Pair(dx, dy, p.count + 1));
        }
    }

    if (counting == 5) {
        int dx = x - dir[d][0];
        int dy = y - dir[d][1];

        if (dx >= 0 && dx < 19 && dy >= 0 && dy < 19 && map[dx][dy] == map[x][y]) {
            counting++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j] == 1 || map[i][j] == 2) {
                for (int d = 0; d < 4; d++) {
                    bfs(i, j, d);

                    if (counting == 5) {
                        cout << map[i][j] << '\n';
                        cout << (i + 1) << " " << (j + 1);
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}
