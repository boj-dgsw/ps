#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int check = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].first >= check) {
            check = arr[i].first + arr[i].second;
        } else {
            check += arr[i].second;
        }
    }

    cout << check << endl;

    return 0;
}
