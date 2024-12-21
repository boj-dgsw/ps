// mo's
// offline query
// Platinum I

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

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

    int n;
    std::cin >> n;

    sqrt_n = std::sqrt(n);

    std::vector<int> arr(n);
    for (auto &val : arr)
    {
        std::cin >> val;
    }

    int m;
    std::cin >> m;

    std::vector<query> queries(m);
    std::vector<int> num_cnts(100'001);
    std::vector<int> cnt_cnts(100'001);
    std::vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> queries[i].s >> queries[i].e;
        queries[i].s--;
        queries[i].e--;

        queries[i].idx = i;
    }

    std::sort(queries.begin(), queries.end(), comp);

    int left = 0, right = 0;
    int max_cnt = 1; // 가장 많이 등장한 횟수
    num_cnts[arr[0]] = 1;
    cnt_cnts[1] = 1;

    for (const auto &[s, e, idx] : queries)
    {
        // 범위 증가
        while (s < left)
        {
            num_cnts[arr[--left]]++;
            if (num_cnts[arr[left]] > max_cnt)
            {
                max_cnt = num_cnts[arr[left]];
            }

            cnt_cnts[num_cnts[arr[left]]]++;
            cnt_cnts[num_cnts[arr[left]] - 1]--;
        }
        while (right < e)
        {
            num_cnts[arr[++right]]++;
            if (num_cnts[arr[right]] > max_cnt)
            {
                max_cnt = num_cnts[arr[right]];
            }

            cnt_cnts[num_cnts[arr[right]]]++;
            cnt_cnts[num_cnts[arr[right]] - 1]--;
        }

        // 범위 감소
        while (left < s)
        {
            cnt_cnts[num_cnts[arr[left]]]--;
            cnt_cnts[num_cnts[arr[left]] - 1]++;
            if (max_cnt == num_cnts[arr[left]] && cnt_cnts[num_cnts[arr[left]]] == 0)
            {
                max_cnt--;
            }
            num_cnts[arr[left++]]--;
        }
        while (e < right)
        {
            cnt_cnts[num_cnts[arr[right]]]--;
            cnt_cnts[num_cnts[arr[right]] - 1]++;
            if (max_cnt == num_cnts[arr[right]] && cnt_cnts[num_cnts[arr[right]]] == 0)
            {
                max_cnt--;
            }
            num_cnts[arr[right--]]--;
        }

        ans[idx] = max_cnt;
    }

    for (auto &val : ans)
    {
        std::cout << val << '\n';
    }
}
