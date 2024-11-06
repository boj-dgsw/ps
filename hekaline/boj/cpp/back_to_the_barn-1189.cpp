// graph searching
// bruteforce
// DFS
// backtrack
// Silver I

#include <bits/stdc++.h>

using namespace std;

int r, c, k, ans;
pair<int, int> coord;
vector<vector<bool>> visited;

void get_way_count(pair<int, int> loc, int dist);
bool is_index_valid(int i, int j)
{ return 0 <= i && i < r && 0 <= j && j < c; }

int main()
{
    cin >> r >> c >> k;
    visited.resize(r, vector<bool>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char temp;
            cin >> temp;

            if (temp == 'T')
            {
                visited[i][j] = true;
                // break;
            }
        }
    }

    visited[r - 1][0] = true;
    get_way_count({r - 1, 0}, 1);
    cout << ans;
}

void get_way_count(pair<int, int> loc, int dist)
{
    if (dist == k)
    {
        ans += loc.first == 0 && loc.second == c - 1;
        return;
    }

    pair<int, int> offsets[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto& [fst, snd] : offsets)
    {
        int new_i = loc.first + fst;
        int new_j = loc.second + snd;

        if (is_index_valid(new_i, new_j) && visited[new_i][new_j] == false)
        {
            visited[new_i][new_j] = true;
            get_way_count({new_i, new_j}, dist + 1);
            visited[new_i][new_j] = false;
        }
    }
}
