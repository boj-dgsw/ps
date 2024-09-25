// Miller-Rabin
// primality test
// math
// Platinum I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using ull = unsigned long long;

constexpr ull bases32[] = { 2, 7, 61 };
bool isPrime32(ull p);
bool millerRabin(ull a, ull p);
ull pow(ull a, ull n, ull mod);

int main()
{
    FAST_IO

    int n;
    int primeCount(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        primeCount += isPrime32(p * 2 + 1);
    }

    cout << primeCount << '\n';
}

bool isPrime32(ull p)
{
    for (auto &base : bases32)
    {
        if (millerRabin(base, p) == false)
            return false;
    }

    return true;
}

bool millerRabin(ull a, ull p)
{
    if (a % p == 0)
        return true;

    ull k = p - 1; // 소수에서 -1을 하면 2^a + d(홀수 or 0)가 됨

    while (true)
    {
        ull power = pow(a, k, p);

        // x^2 % p = +-1
        if (power - p == -1)
        {
            return true;
        }

        // d를 찾음
        if (k & 1)
        {
            return power == 1;
        }

        k >>= 1;
    }
}

ull pow(ull a, ull n, ull mod)
{
    ull ans = 1;
    ull aPow = a % mod;

    while (n)
    {
        if (n & 1)
        {
            ans *= aPow;
            ans %= mod;
        }

        aPow = (aPow * aPow) % mod;
        n >>= 1;
    }

    return ans;
}
