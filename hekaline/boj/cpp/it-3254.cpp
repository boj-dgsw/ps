// implementation
// simulation
// Silver III

#include <bits/stdc++.h>

using namespace std;

constexpr bool SK(false);
constexpr bool JI(true);

vector<vector<bool>> arr(7);

int max_length_from(int idx);
bool is_idx_valid(int i, int j);

int main()
{
    for (int i(1); i <= 21; i++)
    {
        int si, ji;
        cin >> si >> ji;
        si -= 1;
        ji -= 1;

        arr[si].emplace_back(SK);
        if (max_length_from(si) >= 4)
        {
            cout << "sk " << i;
            return 0;
        }

        arr[ji].emplace_back(JI);
        if (max_length_from(ji) >= 4)
        {
            cout << "ji " << i;
            return 0;
        }
    }

    cout << "ss";
}

int max_length_from(int idx)
{
    bool target = arr[idx].back();
    int max_streak(0);
    int temp(1);

    // 상하
    for (int j(arr[idx].size() - 2); j >= 0; j--)
    {
        if (arr[idx][j] != target)
            break;

        temp += 1;
    }

    max_streak = temp;
    temp = 1;

    // 좌우
    int height = arr[idx].size() - 1;
    for (int i(idx - 1); i >= 0; i--)
    {
        if (!is_idx_valid(i, height) || arr[i][height] != target)
            break;

        temp += 1;
    }

    for (int i(idx + 1); i < 7; i++)
    {
        if (!is_idx_valid(i, height) || arr[i][height] != target)
            break;

        temp += 1;
    }

    max_streak = max(max_streak, temp);
    temp = 1;

    // 대각선 (우상)
    for (int i(1); i <= 3; i++)
    {
        pair coord(idx + i, height + i);
        if (!is_idx_valid(coord.first, coord.second) || arr[coord.first][coord.second] != target)
            break;

        temp += 1;
    }

    // 대각선(좌하)
    for (int i(1); i <= 3; i++)
    {
        pair coord(idx - i, height - i);
        if (!is_idx_valid(coord.first, coord.second) ||
            arr[coord.first][coord.second] != target)
            break;

        temp += 1;
    }

    max_streak = max(max_streak, temp);
    temp = 1;

    // 대각선(좌상)
    for (int i(1); i <= 3; i++)
    {
        pair coord(idx - i, height + i);
        if (!is_idx_valid(coord.first, coord.second) ||
            arr[coord.first][coord.second] != target)
            break;

        temp += 1;
    }

    // 대각선(우하)
    for (int i(1); i <= 3; i++)
    {
        pair coord(idx + i, height - i);

        if (!is_idx_valid(coord.first, coord.second) ||
            arr[coord.first][coord.second] != target)
            break;

        temp += 1;
    }

    max_streak = max(max_streak, temp);
    return max_streak;
}

bool is_idx_valid(int i, int j)
{
    if (i < 0 || i >= 7)
        return false;

    if (arr[i].size() <= j)
        return false;

    return true;
}
