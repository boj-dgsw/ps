#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int getCycle(const vector<int>& arr);
void input(int& n, vector<int>& arr)
{
    cin >> n;
    arr.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}

int main()
{
    FAST_IO

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        vector<int> arr;
        input(n, arr);

        cout << getCycle(arr) << '\n';
    }
}

int getCycle(const vector<int> &arr)
{
    int n(arr.size() - 1);
    int ans(0);

    vector visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        ans++;
        int next = arr[i];
        while (true)
        {
            if (visited[next]) break;

            visited[next] = true;
            next = arr[next];
        }
    }

    return ans;
}
