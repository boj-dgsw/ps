#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int SIZE = 5;
int board[SIZE][SIZE];
bool marked[SIZE][SIZE];
unordered_map<int, pair<int, int>> numPos;

bool isBingo() {
    int lines = 0;

    for (int i = 0; i < SIZE; i++) {
        bool bingo = true;
        for (int j = 0; j < SIZE; j++) {
            if (!marked[i][j]) {
                bingo = false;
                break;
            }
        }
        if (bingo) lines++;
    }

    for (int i = 0; i < SIZE; i++) {
        bool bingo = true;
        for (int j = 0; j < SIZE; j++) {
            if (!marked[j][i]) {
                bingo = false;
                break;
            }
        }
        if (bingo) lines++;
    }

    bool bingo = true;
    for (int i = 0; i < SIZE; i++) {
        if (!marked[i][i]) {
            bingo = false;
            break;
        }
    }
    if (bingo) lines++;

    bingo = true;
    for (int i = 0; i < SIZE; i++) {
        if (!marked[i][SIZE - i - 1]) {
            bingo = false;
            break;
        }
    }
    if (bingo) lines++;

    return lines >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
            numPos[board[i][j]] = {i, j};
        }
    }

    queue<int> calls;
    for (int i = 0; i < SIZE * 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num;
            cin >> num;
            calls.push(num);
        }
    }

    int count = 0;
    while (!calls.empty()) {
        int num = calls.front();
        calls.pop();
        count++;

        auto pos = numPos[num];
        marked[pos.first][pos.second] = true;

        if (isBingo()) {
            cout << count << '\n';
            return 0;
        }
    }

    return 0;
}
