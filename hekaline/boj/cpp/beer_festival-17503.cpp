#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

using ll = long long;

int n, m, k;
std::vector<std::pair<int, int>> arr;

bool cmp(std::pair<int, int> const &a, std::pair<int, int> const &b)
{
    if (a.first != b.first)
        return a.first > b.first;

    return a.second < b.second;
}

int get_sum(ll resistance)
{
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < k && cnt < n; i++)
    {
        if (arr[i].second <= resistance)
        {
            sum += arr[i].first;
            cnt++;
        }
    }

    return cnt != n ? 0 : sum;
}

int main()
{
    FAST_IO

    std::cin >> n >> m >> k;
    arr.resize(k);

    for (int i = 0; i < k; i++)
    {
        std::cin >> arr[i].first >> arr[i].second;
    }

    std::ranges::sort(arr, cmp);

    // for (int i = 0; i < k; i++)
    // {
    //     std::cout << arr[i].first << ' ' << arr[i].second << '\n';
    // }

    ll min_resistance = 0;
    ll max_resistance = std::pow(2, 31);

    int rep = 10000;
    while (rep--)
    {
        if (min_resistance > max_resistance)
        {
            std::cout << -1;
            return 0;
        }

        ll mid = (min_resistance + max_resistance) / 2;
        int sum = get_sum(mid);

        if (sum >= m)
        {
            if (get_sum(mid - 1) < m)
            {
                std::cout << mid;
                return 0;
            } else
            {
                max_resistance = mid - 1;
            }
        } else
        {
            min_resistance = mid + 1;
        }
    }

    std::cout << -1;
}
