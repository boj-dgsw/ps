// dp
// Silver I

#include <bits/stdc++.h>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> memo(n + 1);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int d, p;
        std::cin >> d >> p;

        for (int j = n; j >= d; j--)
        {
            memo[j] = std::max(memo[j], memo[j - d] + p);
            ans = std::max(ans, memo[j]);
        }
    }
    std::cout << ans;
}
