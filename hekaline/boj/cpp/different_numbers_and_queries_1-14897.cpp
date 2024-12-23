// mo's
// coordinate compression
// data structures
// offline query
// Platinum II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

struct query
{
    int s, e, idx;
};

int sqrt_n;

void compress_vector(
    std::vector<std::pair<int, int>> const &vec,
    std::vector<int> &out)
{
    int size = vec.size();

    int idx = 0;
    out[vec[0].second] = 0;

    for (int i = 1; i < size; i++)
    {
        if (vec[i - 1].first != vec[i].first)
        {
            idx++;
        }

        out[vec[i].second] = idx;
    }
}

bool comp(query const &a, query const &b)
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

    std::vector<std::pair<int, int>> arr(n);
    std::vector<int> compressed(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i].first;
        arr[i].second = i;
    }
    std::ranges::sort(arr);
    compress_vector(arr, compressed);

    int q;
    std::cin >> q;

    std::vector<query> queries(q);
    for (int i = 0; i < q; i++)
    {
        auto &[s, e, idx] = queries[i];
        std::cin >> s >> e;
        s--; e--;

        idx = i;
    }

    std::ranges::sort(queries, comp);

    int left = 0, right = 0;
    int diff = 1;
    std::vector<int> count(1'000'001);
    std::vector<int> ans_arr(q);
    count[compressed[0]]++;

    for (const auto &[s, e, idx] : queries)
    {
        // 범위 증가
        while (s < left)
        {
            if (count[compressed[left - 1]] == 0)
            {
                diff++;
            }

            count[compressed[--left]]++;
        }
        while (right < e)
        {
            if (count[compressed[right + 1]] == 0)
            {
                diff++;
            }

            count[compressed[++right]]++;
        }

        // 범위 감소
        while (left < s)
        {
            if (count[compressed[left]] == 1)
            {
                diff--;
            }

            count[compressed[left++]]--;
        }
        while (e < right)
        {
            if (count[compressed[right]] == 1)
            {
                diff--;
            }

            count[compressed[right--]]--;
        }

        ans_arr[idx] = diff;
    }

    for (const int &ans : ans_arr)
    {
        std::cout << ans << '\n';
    }
}
