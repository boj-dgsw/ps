// string
// bruteforcing
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);

using namespace std;
using ll = long long;

ll n;

ll getPalindromeNum(ll val);

int main()
{
    cin >> n;

    cout << getPalindromeNum(n);
}


ll getPalindromeNum(ll val)
{
    if (val <= 9) return val;

    string val_s = to_string(val);
    ll valTemp = val;
    ll ans = 9;

    val /= static_cast<ll>(pow(10, val_s.length() / 2));

    while (val > 0)
    {
        string palindrome = to_string(val);
        string palinReverse = palindrome;
        ranges::reverse(palinReverse);

        for (int i = 0; i <= 9; i++)
        {
            string palin2 = palindrome;
            palin2 += to_string(i);
            palin2 += palinReverse;
            if (stoll(palin2) <= valTemp)
            {
                ans++;
            }
        }

        palindrome += palinReverse;
        if (stoll(palindrome) <= valTemp)
        {
            ans++;
        }

        val--;
    }

    return ans;
}
