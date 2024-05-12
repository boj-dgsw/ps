#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        for (int j = a; j <= a + ((b - a) / 2); ++j) {
            swap(arr[j], arr[b + a - j]);
        }
    }

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
