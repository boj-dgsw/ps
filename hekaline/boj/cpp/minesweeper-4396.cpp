// implementation
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

int n;
std::vector<std::vector<char>> mine_map;
std::vector<std::vector<char>> open_map;

bool is_index_valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

char num_to_char(int n)
{
    return '0' + n;
}

int mine_count_nearby(int i, int j)
{
    int res = 0;
    std::array offset { -1, 0, 1 };

    for (int &i_offset : offset)
    {
        for (int &j_offset : offset)
        {
            if (i_offset == 0 && j_offset == 0)
                continue;

            int new_i = i + i_offset;
            int new_j = j + j_offset;

            if (!is_index_valid(new_i, new_j))
                continue;

            res += mine_map[new_i][new_j] == '*';
        }
    }

    return res;
}

int main()
{
    FAST_IO

    std::cin >> n;

    mine_map.resize(n, std::vector<char>(n));
    for (auto &line : mine_map)
    {
        for (char &val : line)
        {
            std::cin >> val;
        }
    }

    open_map.resize(n, std::vector<char>(n));
    for (auto &line : open_map)
    {
        for (char &val : line)
        {
            std::cin >> val;
        }
    }

    bool has_touched_mine = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (open_map[i][j] == 'x' && mine_map[i][j] == '*')
            {
                has_touched_mine = true;
            }

            if (open_map[i][j] == 'x' && mine_map[i][j] != '*')
            {
                open_map[i][j] = num_to_char(mine_count_nearby(i, j));
            }
        }
    }

    if (has_touched_mine)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mine_map[i][j] == '*')
                    open_map[i][j] = '*';
            }
        }
    }

    for (auto &line : open_map)
    {
        for (char &val : line)
        {
            std::cout << val;
        } std::cout << '\n';
    }
}
