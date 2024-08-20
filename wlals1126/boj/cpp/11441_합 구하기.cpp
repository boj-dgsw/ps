#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }

    int m;
    cin >> m;

    stringstream ss;

    for (int i = 0; i < m; ++i) {
        int left, right;
        cin >> left >> right;
        ss << (arr[right] - arr[left - 1]) << "\n";
    }

    cout << ss.str();

    return 0;
}
