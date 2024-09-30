// implementation
// simulation

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr char EMPTY = '.';
constexpr char BOMB = 'O';

void get_arr_after_seconds(vector<vector<pair<char, int>>> &arr, int seconds);
void print_arr(vector<vector<pair<char, int>>> &arr);
void plant_bomb(vector<vector<pair<char, int>>> &arr, int curr_second);
void explode(vector<vector<pair<char, int>>> &arr, int curr_second);
bool is_index_valid(int i, int j, int r, int c)
{ return i >= 0 && j >= 0 && i < r && j < c; }

int main()
{
    FAST_IO

    int r, c, n;
    cin >> r >> c >> n;

    // [r][c] { bomb/empty, planted time }
    vector arr(r, vector<pair<char, int>>(c));

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < c; j++)
        {
            arr[i][j] = { s[j], 0 };
        }
    }

    get_arr_after_seconds(arr, n);
    print_arr(arr);
}

void get_arr_after_seconds(vector<vector<pair<char, int>>> &arr, int seconds)
{
    // 폭탄 설치 턴인가?
    bool is_going_to_plant = true;

    // 첫 1초 동안 봄버맨은 아무것도 하지 않음
    for (int curr_second = 2; curr_second <= seconds; curr_second++)
    {
        if (is_going_to_plant)
        {
            plant_bomb(arr, curr_second);
        } else
        {
            explode(arr, curr_second);
        }

        is_going_to_plant = !is_going_to_plant;
    }
}

void plant_bomb(vector<vector<pair<char, int>>> &arr, int curr_second)
{
    for (auto& line : arr)
    {
        for (auto& val : line)
        {
            if (val.first == BOMB)
                continue;

            val.first = BOMB;
            val.second = curr_second;
        }
    }
}

void explode(vector<vector<pair<char, int>>> &arr, int curr_second)
{
    int r = arr.size();
    int c = arr[0].size();

    vector<pair<int, int>> coords;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j].first == EMPTY)
                continue;

            if (arr[i][j].second + 3 > curr_second)
                continue;

            arr[i][j].first = EMPTY;

            if (is_index_valid(i + 1, j, r, c))
                coords.emplace_back(i + 1, j);

            if (is_index_valid(i - 1, j, r, c))
                coords.emplace_back(i - 1, j);

            if (is_index_valid(i, j - 1, r, c))
                coords.emplace_back(i, j - 1);

            if (is_index_valid(i, j + 1, r, c))
                coords.emplace_back(i, j + 1);
        }
    }

    for (const auto &coord : coords)
    {
        arr[coord.first][coord.second].first = EMPTY;
    }
}

void print_arr(vector<vector<pair<char, int>>> &arr)
{
    for (const auto &line : arr)
    {
        for (const auto &val : line)
        {
            cout << val.first;
        }
        cout << '\n';
    }
}
