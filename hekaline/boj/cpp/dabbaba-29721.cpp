// hash
// data structures
// implementation
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

bool is_index_valid(int i, int j, int n)
{
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main()
{
    FAST_IO

    int n, k;
    std::cin >> n >> k;

    std::set<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> coords(k);

    for (int i = 0; i < k; i++)
    {
        auto &[f, s] = coords[i];
        std::cin >> f >> s;
        visited.emplace(coords[i]);
    }

    std::vector<std::pair<int, int>> offsets {{-2, 0}, {0, 2}, {2, 0}, {0, -2}};
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        auto &[f, s] = coords[i];

        for (auto const &[i_offset, j_offset] : offsets)
        {
            int new_i = f + i_offset;
            int new_j = s + j_offset;

            if (is_index_valid(new_i, new_j, n) && !visited.contains({new_i, new_j}))
            {
                ans++;
                visited.emplace(new_i, new_j);
            }
        }
    }

    std::cout << ans;
}
