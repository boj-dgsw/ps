#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    if (n % 2 == 0 || n % 5 == 0)
    {
        cout << -1;
        return 0;
    }

    int ans(0), j(0);

    while (true)
    {
        ans++;
        j = (j * 10 + 1) % n;

        if (j == 0)
        {
            cout << ans;
            return 0;
        }
    }
}
