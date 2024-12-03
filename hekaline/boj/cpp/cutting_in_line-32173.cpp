// greedy
// prefix sum
// Silver III

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);

using ull = unsigned long long;

int main()
{
    FAST_IO

    int n;
    std::cin >> n;

    std::vector<ull> arr(n);
    std::vector<ull> sum(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        sum[i] = arr[i];

        if (i != 0)
        {
            sum[i] += sum[i - 1];
        }
    }

    ull ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (sum[i - 1] <= arr[i])
        {
            ans = std::max(ans, arr[i] - sum[i - 1]);
        }
    }

    std::cout << ans;
}
