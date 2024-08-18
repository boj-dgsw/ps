// bruteforcing
// recursion
// implementation
// Silver III

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ans(0);
int n, m;
int arr[2][3];
int visited[3] { -2, -2, -2 };

void recursion(int th, int val)
{
    if (th == n)
    {
        if (val >= m) ans++;
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int add;
            if (visited[j] == th - 1) add = arr[i][j] / 2;
            else add = arr[i][j];

            int tmp = visited[j];
            visited[j] = th;
            recursion(th + 1, val + add);
            visited[j] = tmp;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    recursion(0, 0);
    cout << ans;
}
