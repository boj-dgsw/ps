// mathematics
// combinatorics
// game theory

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr) ;

using ll = long long;
constexpr ll DIV = 1e9 + 7;

// 1, 1, 26, 26, 26^2, 26^2, 26^3, 26^3, ...

int main()
{
    FAST_IO

    ll l, u;
    std::cin >> l >> u;

    bool hoyoung = l == 2 || (l == 1 && u == 1 && l < 3);

    ll sum = 0, plus = 1;

    for (ll i = 1; i <= u; i++)
    {
        if (i % 2 && i != 1)
        {
            plus = (plus * 26) % DIV;
        }

        if (i >= l)
        {
            sum = (sum + plus) % DIV;
        }
    }

    std::cout << (hoyoung ? "H" : "A") << '\n';
    std::cout << sum;
}
