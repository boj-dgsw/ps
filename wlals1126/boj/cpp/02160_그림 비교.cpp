#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<vector<char>>> map(N, vector<vector<char>>(5, vector<char>(7)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < 7; k++) {
                map[i][j][k] = s[k];
            }
        }
    }

    int num = 0;
    int min_diff = INT_MAX;
    int x = 0, y = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            num = 0;

            for (int nx = 0; nx < 5; nx++) {
                for (int ny = 0; ny < 7; ny++) {
                    if (map[i][nx][ny] != map[j][nx][ny]) {
                        num++;
                    }
                }
            }

            if (num < min_diff) {
                min_diff = num;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
