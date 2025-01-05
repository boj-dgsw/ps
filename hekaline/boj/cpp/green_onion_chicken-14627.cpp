// binary search
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);
// #define DEBUG

using ll = long long;

std::vector<ll> arr;

ll get_count(ll length)
{
    long long res = 0;
    for (const auto &val : arr)
    {
        res += val / length;
    }

    return res;
}

int main()
{
    FAST_IO;

    int s, c;
    std::cin >> s >> c;
    arr.resize(s);

    ll min = 1;
    ll max = -1;

    for (auto &val : arr)
    {
        std::cin >> val;
        max = std::max(max, val);
    }

    while (min <= max)
    {
        ll mid = (min + max) / 2;
#ifdef DEBUG
        std::cout << "min: " << min << ", max: " << max << '\n';
        std::cout << "mid: " << mid << '\n';
#endif

        if (get_count(mid) >= c)
        {
            if (get_count(mid + 1) < c)
            {
                // 남은 파 길이
                ll res = 0;
                ll cnt = 0;
                for (int i = 0; i < s; i++)
                {
                    const auto &val = arr[i];
                    res += val % mid;
                    cnt += val / mid;

                    if (cnt >= c)
                    {
                        res += mid * (cnt - c);
                        for (int j = i + 1; j < s; j++)
                        {
                            res += arr[j];
                        }
                        break;
                    }
                }

                std::cout << res;
                return 0;
            }

            min = mid + 1;
        } else
        {
            max = mid - 1;
        }
    }
}
