// mathematics
// implementation
// Bronze I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using ll = long long;
constexpr long long DIV = 1e9 + 7;

ll m_mul(ll a, ll b)
{
    a %= DIV;
    b %= DIV;

    return (a * b) % DIV;
}


int main()
{
    FAST_IO;

    ll n, x;
    cin >> n >> x;

    int ai, i;
    cin >> ai >> i;

    ll ans = m_mul(ai, x);

    for (int idx = 1; idx < n; idx++)
    {
        cin >> ai >> i;

        ans += ai;
        ans %= DIV;
        ans = m_mul(ans, x);
    }
    
    cin >> ai >> i;
    ans += ai;

    cout << ans % DIV;
}
