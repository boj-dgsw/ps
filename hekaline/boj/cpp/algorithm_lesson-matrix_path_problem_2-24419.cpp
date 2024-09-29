// dynamic programming
// mathematics

#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int main()
{
    int n;
    cin >> n;

    vector arr(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = arr[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % MOD;
        }
    }

    cout << arr[n][n] << ' ' << n * n;
}
