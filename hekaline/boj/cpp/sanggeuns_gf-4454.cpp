// binary search
// parametic search
// Silver I

#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld a, b, c, d, m, t;

bool input()
{
    cin >> a >> b >> c >> d >> m >> t;

    return !cin.eof();
}

ld consumption(ld v)
{
    return (a * pow(v, 3) + b * pow(v, 2) + c * v + d) * m;
}

ld get_ans()
{
    ld left = 0, right = 100000;
    ld ans = 0;

    int i = 400;

    while (i--)
    {
        ld v = (left + right) / 2;
        ld consume = consumption(v);

        if (consume <= t)
        {
            ans = v;
            left = v;
        } else
        {
            right = v;
        }
    }

    return ans;
}

int main()
{
    cout << fixed;
    cout.precision(2);

    while (input())
    {
        cout << (long long)(get_ans() * 100) / 100.l << '\n';
    }
}
