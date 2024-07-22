#include <iostream>
#include <vector>

using namespace std;

int x, y, n;
vector<vector<char>> arr;

bool DU(int a, int b);
bool RL(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    arr.resize(n, vector<char>(n, '.'));

    string str;
    cin >> str;

    x = 0;
    y = 0;
    bool flag;

    for (char c : str) {
        if (c == 'D') {
            flag = DU(x + 1, y);
            if (flag) {
                x += 1;
            }
        } else if (c == 'R') {
            flag = RL(x, y + 1);
            if (flag) {
                y += 1;
            }
        } else if (c == 'L') {
            flag = RL(x, y - 1);
            if (flag) {
                y -= 1;
            }
        } else {
            flag = DU(x - 1, y);
            if (flag) {
                x -= 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}

bool DU(int a, int b) {
    if (a >= 0 && a < n && b >= 0 && b < n) {
        if (arr[x][y] == '-') {
            arr[x][y] = '+';
        } else if (arr[x][y] == '.') {
            arr[x][y] = '|';
        }

        if (arr[a][b] == '-') {
            arr[a][b] = '+';
        } else if (arr[a][b] == '.') {
            arr[a][b] = '|';
        }
        return true;
    }
    return false;
}

bool RL(int a, int b) {
    if (a >= 0 && a < n && b >= 0 && b < n) {
        if (arr[x][y] == '|') {
            arr[x][y] = '+';
        } else if (arr[x][y] == '.') {
            arr[x][y] = '-';
        }

        if (arr[a][b] == '|') {
            arr[a][b] = '+';
        } else if (arr[a][b] == '.') {
            arr[a][b] = '-';
        }
        return true;
    }
    return false;
}
