#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, kingX, kingY, rockX, rockY;
vector<vector<int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int getDirection(const string& order) {
    if (order == "R") {
        return 2;
    } else if (order == "L") {
        return 6;
    } else if (order == "B") {
        return 4;
    } else if (order == "T") {
        return 0;
    } else if (order == "RT") {
        return 1;
    } else if (order == "LT") {
        return 7;
    } else if (order == "RB") {
        return 3;
    } else if (order == "LB") {
        return 5;
    }
    return -1;
}

bool isRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string king, rock;
    cin >> king >> rock >> n;

    kingX = 7 - (king[1] - '0' - 1);
    kingY = king[0] - 'A';

    rockX = 7 - (rock[1] - '0' - 1);
    rockY = rock[0] - 'A';

    for (int i = 0; i < n; i++) {
        string order;
        cin >> order;
        int orderNum = getDirection(order);
        
        if (isRange(kingX + dir[orderNum][0], kingY + dir[orderNum][1])) {
            kingX += dir[orderNum][0];
            kingY += dir[orderNum][1];

            if (kingX == rockX && kingY == rockY) {
                if (isRange(rockX + dir[orderNum][0], rockY + dir[orderNum][1])) {
                    rockX += dir[orderNum][0];
                    rockY += dir[orderNum][1];
                } else {
                    kingX -= dir[orderNum][0];
                    kingY -= dir[orderNum][1];
                    continue;
                }
            }
        } else {
            continue;
        }
    }

    cout << static_cast<char>(kingY + 'A') << (8 - kingX) << endl;
    cout << static_cast<char>(rockY + 'A') << (8 - rockX) << endl;

    return 0;
}
