// implementation
// bitmasking

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 0b000000;
    int target;

    cin >> target;

    int ans = 0;

    for (int i = 6; i >= 0; i--)
    {
        if (x + (1 << i) <= target)
        {
            x += (1 << i);
            ans++;
        }
    }

    cout << ans;
}
