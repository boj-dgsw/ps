// mo's
// offline query
// Platinum II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

using ll = long long;

int sqrt_n;

struct query
{
    int s, e, idx;
};

bool comp(const query &a, const query &b)
{
    if (a.s / sqrt_n != b.s / sqrt_n)
    {
        return a.s / sqrt_n < b.s / sqrt_n;
    }

    return a.e < b.e;
}

int main()
{
    FAST_IO

    int n, t;
    std::cin >> n >> t;

    sqrt_n = std::sqrt(n);

    std::vector<ll> arr(n);
    std::vector<query> queries(t);
    for (auto &val : arr)
    {
        std::cin >> val;
    }

    for (int i = 0; i < t; i++)
    {
        auto &[s, e, idx] = queries[i];

        std::cin >> s >> e;
        s--; e--;
        idx = i;
    }

    std::ranges::sort(queries, comp);

    std::vector<ll> ans_arr(t);
    std::vector<ll> counts(1'000'001);

    int left = 0, right = 0;
    ll ans = arr[0];
    counts[arr[0]]++;

    for (const auto &[s, e, idx] : queries)
    {
        // 범위 증가
        while (s < left)
        {
            // 이전 배열의 힘 지우고 새로 쓰기
            if (counts[arr[left - 1]] != 0)
            {
                ans -= counts[arr[left - 1]] * counts[arr[left - 1]] * arr[left - 1];
            }

            counts[arr[left - 1]]++;
            ans += counts[arr[left - 1]] * counts[arr[left - 1]] * arr[left - 1];
            left--;
        }
        while (right < e)
        {
            // 이전 배열의 힘 지우고 새로 쓰기
            if (counts[arr[right + 1]] != 0)
            {
                ans -= counts[arr[right + 1]] * counts[arr[right + 1]] * arr[right + 1];
            }

            counts[arr[right + 1]]++;
            ans += counts[arr[right + 1]] * counts[arr[right + 1]] * arr[right + 1];
            right++;
        }

        // 범위 감소
        while (left < s)
        {
            ans -= counts[arr[left]] * counts[arr[left]] * arr[left];
            counts[arr[left]]--;
            ans += counts[arr[left]] * counts[arr[left]] * arr[left];
            left++;
        }
        while (e < right)
        {
            ans -= counts[arr[right]] * counts[arr[right]] * arr[right];
            counts[arr[right]]--;
            ans += counts[arr[right]] * counts[arr[right]] * arr[right];
            right--;
        }

        ans_arr[idx] = ans;
    }

    for (const auto &answer : ans_arr)
    {
        std::cout << answer << '\n';
    }

    return 0;
}
