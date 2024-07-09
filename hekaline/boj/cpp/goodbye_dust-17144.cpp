// 미세먼지 확산 이후 공기청정기 작동

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int r, c, t;
vector<vector<int>> arr;
int sum = 2; // 공기청정기는 -1 * 2칸
pair<short, short> purifierCoord(-1, -1);

void input();
void spreadDust();
void tryFillCross(const pair<short, short>& coord, int value);
void purifierBlow(pair<short, short> start, bool ccw = false);

pair<short, short> operator+(const pair<short, short>& lhs, const pair<short, short>& rhs)
{
    return {lhs.first + rhs.first, lhs.second + rhs.second };
}
pair<short, short> operator-(const pair<short, short>& lhs, const pair<short, short>& rhs)
{
    return {lhs.first - rhs.first, lhs.second - rhs.second };
}

bool isValid(int i, int j)
{ return i >= 0 && j >= 0 && i < r && j < c; }

void debugPrint()
{
    for (const auto& line : arr)
    {
        for (const auto& element : line)
        {
            cout << element << ' ';
        } cout << '\n';
    } cout << '\n';
}

int main()
{
    FAST_IO;
    input();

    for (int i = 0; i < t; i++)
    {
        spreadDust();

        purifierBlow(purifierCoord, true);
        purifierBlow(purifierCoord + pair<short, short>{1, 0});
        // debugPrint();
    }

    cout << sum;
}

void purifierBlow(pair<short, short> start, bool ccw)
{
    pair<short, short> cwDirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    pair<short, short> ccwDirs[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    auto& dirs = ccw ? ccwDirs : cwDirs;

    pair<short, short> currCoord = start;
    int temp;
    int prev = 0;

    for (const auto& dir : dirs)
    {
        while (true)
        {
            currCoord = currCoord + dir;
            if (!isValid(currCoord.first, currCoord.second))
            {
                // operator-
                currCoord = currCoord - dir;
                break;
            }
            if (arr[currCoord.first][currCoord.second] == -1)
            {
                sum -= prev;
                return;
            }

            temp = arr[currCoord.first][currCoord.second];
            arr[currCoord.first][currCoord.second] = prev;
            prev = temp;
        }
    }
}

void tryFillCross(const pair<short, short>& coord, int value)
{
    pair<short, short> offsets[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto& offset: offsets)
    {
        pair<short, short> newCoord = coord + offset;

        if (!isValid(newCoord.first, newCoord.second) ||
            arr[newCoord.first][newCoord.second] == -1)
        {
            continue;
        }

        arr[newCoord.first][newCoord.second] += value / 5;
        arr[coord.first][coord.second] -= (value / 5);
    }
}



void spreadDust()
{
    queue<pair<pair<short, short>, int>> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] > 0)
            {
                q.push({{i, j}, arr[i][j]});
            }
        }
    }

    while (!q.empty())
    {
        pair<short, short> coord = q.front().first;
        int value = q.front().second;
        q.pop();

        tryFillCross(coord, value);
    }

    // debugPrint();
}

void input()
{
    cin >> r >> c >> t;

    arr.resize(r);
    for (int i = 0; i < r; i++)
    {
        arr[i].resize(c);
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];

            // purifier coord is not set
            if (arr[i][j] == -1 && purifierCoord.first == -1)
            {
                purifierCoord = {i, j};
            }
        }
    }
}
