// dp
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n);
    int max_len = 1;

    for (int target = 0; target < n; target++)
    {
        dp[target] = 1;
        for (int i = 0; i < target; i++)
        {
            if (arr[i] > arr[target])
            {
                dp[target] = max(dp[target], dp[i] + 1);
                max_len = max(max_len, dp[target]);
            }
        }
    }

    cout << n - max_len;
}
