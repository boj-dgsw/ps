#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(5));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<unordered_set<int>> result(n);
    vector<vector<int>> list(10);

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 10; ++i) {
            list[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            list[arr[i][j]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (list[arr[i][j]].size() > 1) {
                for (int k : list[arr[i][j]]) {
                    result[i].insert(k);
                }
            }
        }
    }

    int max = 0;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (max < result[i].size()) {
            max = result[i].size();
            answer = i;
        }
    }
    cout << answer + 1 << endl;

    return 0;
}
