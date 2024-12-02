// dynamic programming
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

int main()
{
    FAST_IO

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int &val : arr)
    {
        std::cin >> val;
    }

    int max_val = 1;
    std::vector<int> max_streak(n);

    for (int i = 0; i < n; i++)
    {
        max_streak[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i]) continue;

            max_streak[i] = std::max(max_streak[i], max_streak[j] + 1);
            max_val = std::max(max_val, max_streak[i]);
        }
    }

    std::cout << max_val;
}
