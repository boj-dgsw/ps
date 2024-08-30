// Mathematics
// Combinatorics
// Silver V

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

constexpr int DIV = 1'000'000'009;
constexpr char CHAR = 'c';
constexpr char NUM = 'd';

int main()
{
    FAST_IO;

    string s;
    cin >> s;

    int len = s.length();
    long long ans = s[0] == NUM ? 10 : 26;

    for (int i = 1; i < len; i++)
    {
        bool isPrevNum = s[i - 1] == NUM;
        bool isCurrNum = s[i] == NUM;

        int mul = isCurrNum ? 10 : 26;

        if (isPrevNum == isCurrNum)
        {
            mul -= 1;
        }

        ans *= mul;
        ans %= DIV;
    }

    cout << ans;
}
