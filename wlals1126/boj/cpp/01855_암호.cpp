#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    string input;
    cin >> input;
    int N = input.length() / K;
    vector<vector<char>> board(N, vector<char>(K));

    int idx = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < K; ++j) {
                board[i][j] = input[idx++];
            }
        } else {
            for (int j = K - 1; j >= 0; --j) {
                board[i][j] = input[idx++];
            }
        }
    }

    string result;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            result += board[j][i];
        }
    }

    cout << result << endl;
    return 0;
}
