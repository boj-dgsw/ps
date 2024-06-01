#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T-- > 0) {
        int cnt = 0;
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[j][i] == 1) {
                    for (int k = j + 1; k < m; ++k) {
                        if (arr[k][i] == 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
        
        cout << cnt << endl;
    }

    return 0;
}
