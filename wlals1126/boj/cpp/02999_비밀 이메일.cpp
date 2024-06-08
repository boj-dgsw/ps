#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    int length = line.length();
    int r = 0;
    int c = 0;
    for (int j = 1; j <= length; j++) {
        for (int i = 1; i <= j; i++) {
            if (j * i == length && r < i) {
                r = i;
                c = j;
            }
        }
    }

    vector<vector<char>> map(r, vector<char>(c));
    int index = 0;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            map[i][j] = line[index++];
        }
    }

    string result;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result += map[i][j];
        }
    }

    cout << result << endl;
    return 0;
}