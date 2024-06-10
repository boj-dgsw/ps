#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> dp(70);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 70; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
