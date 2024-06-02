#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int r, c;
int maxCnt;
bool visited[26];
vector<vector<char>> arr;

void input();
void backtrack(int i, int j, int cnt);
void backtrack() { backtrack(0, 0, 1); }

int main()
{
    FAST_IO;
    input();

    visited[arr[0][0] - 'A'] = true;
    backtrack();

    cout << maxCnt;
}

bool isValid(int i, int j)
{ return i >= 0 && j >= 0 && i < r && j < c; }

void backtrack(int i, int j, int cnt)
{
    maxCnt = max(maxCnt, cnt);

    pair<int, int> offsets[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto offset : offsets)
    {
        int newI = i + offset.first;
        int newJ = j + offset.second;

        if (isValid(newI, newJ) && !visited[arr[newI][newJ] - 'A'])
        {
            visited[arr[newI][newJ] - 'A'] = true;
            backtrack(newI, newJ, cnt + 1);
            visited[arr[newI][newJ] - 'A'] = false;
        }
    }
}

void input()
{
    cin >> r >> c;

    arr.resize(r);
    for (int i = 0; i < r; i++)
    {
        arr[i].resize(c);
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
}
