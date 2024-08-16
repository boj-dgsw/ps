#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int redCnt(0);
    int blueCnt(0);

    int i(0);
    while (i < n)
    {
        s[i] == 'R' ? redCnt += 1 : blueCnt += 1;
        while (i + 1 < n && s[i] == s[i + 1])
        {
            i++;
        }
        i++;
    }

    int ans = min(redCnt, blueCnt) + 1;
    if (s[i] == s[n - 1])
        ans -= 1;

    cout << ans;
}
