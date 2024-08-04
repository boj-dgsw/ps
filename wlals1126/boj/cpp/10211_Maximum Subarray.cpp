#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bottomUp(const vector<int>& arr, int& maxSum) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    maxSum = dp[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T-- > 0) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        int maxSum;
        bottomUp(arr, maxSum);
        cout << maxSum << endl;
    }

    return 0;
}
