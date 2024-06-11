#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> dp(n, vector<int>(3, 0));
        vector<vector<int>> graph(n, vector<int>(2, 0));

        for (int i = 0; i < n; i++) {
            cin >> graph[i][0];
        }
        for (int i = 0; i < n; i++) {
            cin >> graph[i][1];
        }

        dp[0][0] = 0;
        dp[0][1] = graph[0][0];
        dp[0][2] = graph[0][1];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + graph[i][0];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + graph[i][1];
        }

        int max_value = max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
        cout << max_value << '\n';
    }

    return 0;
}
