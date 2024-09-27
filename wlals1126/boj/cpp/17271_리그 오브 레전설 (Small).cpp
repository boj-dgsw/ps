#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1];
        if (i >= M) {
            dp[i] = (dp[i] + dp[i - M]) % MOD;
        }
    }

    cout << dp[N] << endl;
    return 0;
}
