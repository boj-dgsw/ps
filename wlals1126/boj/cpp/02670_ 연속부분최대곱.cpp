#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> arr(n), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    double max_value = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] * dp[i], dp[i]);
        max_value = max(max_value, dp[i]);
    }

    cout << fixed << setprecision(3) << max_value << endl;

    return 0;
}
