// math
// number theory
// euclidean algorithm
// Silver I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using ll = long long;

int main()
{
    FAST_IO;
    
    int n;
    cin >> n;

    long long molecule = 1;
    long long denominator = 1;

    cin >> molecule >> denominator;
    {
        const ll _gcd = gcd(molecule, denominator);
        molecule /= _gcd;
        denominator /= _gcd;
    }

    while (--n)
    {
        ll a, b;
        cin >> a >> b;

        const ll _gcd = gcd(a, b);

        a /= _gcd;
        b /= _gcd;

        if (denominator % b == 0)
        {
            const ll mul = denominator / b;

            a *= mul;
            b *= mul;
        }

        molecule = gcd(molecule, a);
        denominator = lcm(denominator, b);
    }

    cout << molecule << ' ' << denominator;
}
