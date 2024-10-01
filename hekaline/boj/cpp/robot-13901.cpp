// implementation
// simulation
// Silver I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr int UP = 1;
constexpr int DOWN = 2;
constexpr int LEFT = 3;
constexpr int RIGHT = 4;

vector<vector<bool>> visited;
vector<int> dirs(4);
int r, c, k;
int sr, sc;

void input();
bool can_visit(int i, int j)
{
    bool is_index_valid = 0 <= i && i < r && 0 <= j && j < c;
    return is_index_valid && visited[i][j] == false;
}

void execute_robot();

int main()
{
    FAST_IO;
    input();

    execute_robot();
    cout << sr << ' ' << sc;
}

void execute_robot()
{
    int i = 0;
    bool visited_anywhere = false;
    pair<int, int> dir;

    while (true)
    {
        if (i >= 4)
        {
            if (visited_anywhere == false)
                break;

            i = 0;
            visited_anywhere = false;
        }

        switch (dirs[i])
        {
            case UP: dir = {-1, 0}; break;
            case DOWN: dir = {1, 0}; break;
            case LEFT: dir = {0, -1}; break;
            case RIGHT: dir = {0, 1}; break;

            default: break;
        }

        visited_anywhere = visited_anywhere || can_visit(sr + dir.first, sc + dir.second);
        while (can_visit(sr + dir.first, sc + dir.second))
        {
            sr += dir.first;
            sc += dir.second;

            visited[sr][sc] = true;
        }

        i++;
    }
}

void input()
{
    cin >> r >> c >> k;
    visited.resize(r, vector<bool>(c));

    for (int i = 0; i < k; i++)
    {
        int br, bc;
        cin >> br >> bc;

        visited[br][bc] = true;
    }

    cin >> sr >> sc;
    visited[sr][sc] = true;

    for (int i = 0; i < 4; i++)
    {
        cin >> dirs[i];
    }
}
