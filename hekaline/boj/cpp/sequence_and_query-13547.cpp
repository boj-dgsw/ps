// mo's
// offline query
// Platinum II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr); 

int n, m;
int sqrt_n;

struct query
{
    int s, e, idx;
};

bool comp(const query& a, const query& b)
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
    
    std::cin >> n;
    sqrt_n = std::sqrt(n);

    std::vector<int> arr(n);
    for (auto &val : arr)
    {
        std::cin >> val;
    }

    std::cin >> m;
    std::vector<query> queries(m);
    std::vector<int> ans_arr(m);
    std::vector<int> num_counts(1'000'001);

    for (int i = 0; i < m; i++)
    {
        std::cin >> queries[i].s >> queries[i].e;
        queries[i].s--;
        queries[i].e--;
        queries[i].idx = i;
    }

    std::ranges::sort(queries, comp);
    int left = 0, right = 0;
    int ans = 1; // arr[0]의 숫자 하나 포함
    num_counts[arr[0]]++;

    for (auto const &[s, e, idx] : queries)
    {
        // 범위 증가
        while (s < left)
        {
            if (num_counts[arr[left - 1]] == 0)
            {
                ans++;
            }
            num_counts[arr[--left]]++;
        }
        while (e > right)
        {
            if (num_counts[arr[right + 1]] == 0)
            {
                ans++;
            }
            num_counts[arr[++right]]++;
        }

        // 범위 감소
        while (left < s)
        {
            if (num_counts[arr[left]] == 1)
            {
                ans--;
            }
            num_counts[arr[left++]]--;
        }
        while (right > e)
        {
            if (num_counts[arr[right]] == 1)
            {
                ans--;
            }
            num_counts[arr[right--]]--;
        }

        ans_arr[idx] = ans;
    }

    for (const auto &answer : ans_arr)
    {
        std::cout << answer << '\n';
    }
}
