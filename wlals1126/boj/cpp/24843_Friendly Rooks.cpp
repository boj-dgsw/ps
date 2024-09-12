#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > n || k > m) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    vector<vector<char>> board(n, vector<char>(m, '.'));

    for (int i = 0; i < k; ++i) {
        board[i][i] = '*';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
