#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> arr; // { up, down }
void input();
int getMinFloor();

int main()
{
    input();

    cout << getMinFloor();
}

int getMinFloor()
{
    int left, right;
    int minFloor = 2'147'483'647;

    for (int i = 0; i < m; i++)
    {
        int res = 2'147'483'647;

        left = 0;
        right = n;
        int up = arr[i].first;
        int down = arr[i].second;

        while (left <= right)
        {
            int downCnt = (left + right) / 2;
            int floor = (up * (n - downCnt)) - (down * downCnt);
            if (floor >= 1)
            {
                res = min(res, floor);
                left = downCnt + 1;
            } else
            {
                right = downCnt - 1;
            }
        }

        minFloor = min(minFloor, res);
    }

    return minFloor;
}

void input()
{
    cin >> n >> m;

    arr.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
}
