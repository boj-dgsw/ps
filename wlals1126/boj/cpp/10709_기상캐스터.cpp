#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> sky(h);
    vector<vector<int>> result(h, vector<int>(w, 999));

    for (int i = 0; i < h; i++) {
        cin >> sky[i];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sky[i][j] == 'c') {
                for (int k = 0; k < w; k++) {
                    if (j + k >= w) continue;
                    result[i][j + k] = min(result[i][j + k], k);
                }
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; j++) {
            if (result[i][j] == 999) {
                cout << -1 << " ";
            } else {
                cout << result[i][j] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
