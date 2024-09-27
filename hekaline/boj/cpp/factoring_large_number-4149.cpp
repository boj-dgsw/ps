// miller-rabin
// pollard-rho
// Platinum I

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using i64 = long long;
using i128 = __int128;


namespace miller_rabin_64
{
    constexpr i64 bases[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    bool is_prime(i128 n);
    bool is_probable_prime(i128 a, i128 n);
}

namespace pollards_rho_64
{
    void get_prime_factor(i128 n);
}

vector<i64> ans;
void get_ans(i128 n);
i64 pow_mod(i128 a, i128 n, i128 mod);
i64 mul_mod(i128 a, i128 b, i128 mod);
i128 abs128(i128 val) { return val < 0 ? -val : val; }

int main()
{
    FAST_IO;

    i64 n;
    cin >> n;

    get_ans(n);

    for (const i64& prime_factor : ans)
    {
        cout << prime_factor << '\n';
    }
}

void pollards_rho_64::get_prime_factor(i128 n)
{
    if (n == 1) return;

    if (n % 2 == 0)
    {
        ans.push_back(2);
        get_prime_factor(n / 2);

        return;
    }

    if (miller_rabin_64::is_prime(n))
    {
        ans.push_back(n);

        return;
    }

    i128 a, b, randAdd;
    i128 _gcd = n;

    auto func = [&](i128 x) {
        return (mul_mod(x, x, n) + randAdd) % n;
    };

    do
    {
        if (_gcd == n)
        {
            a = b = rand() % (n - 2) + 2;
            randAdd = rand() % 20 + 1;
        }

        a = func(a);
        b = func(func(b));
        _gcd = gcd(abs128(a - b), n);
    } while (_gcd == 1);

    get_prime_factor(_gcd);
    get_prime_factor(n / _gcd);
}


bool miller_rabin_64::is_prime(i128 n)
{
    if (n != 2 && n % 2 == 0)
        return false;

    for (const auto& base : bases)
    {
        if (base == n) return true;
        if (is_probable_prime(base, n) == false)
            return false;
    }

    return true;
}

bool miller_rabin_64::is_probable_prime(i128 a, i128 n)
{
    if (a % n == 0)
        return true;

    i128 k = n - 1;

    while (true)
    {
        i128 power = pow_mod(a, k, n);

        // k가 0이어도 power가 1일 가능성이 있으므로 체크
        if (k & 1) // if (k % 2 == 1)
        {
            return power == 1 || power == n - 1;
        }

        // power % n == -1
        if (power == n - 1) return true;

        k >>= 1; // k /= 2
    }
}

void get_ans(i128 n)
{
    // if n is prime return n
    if (miller_rabin_64::is_prime(n))
    {
        ans = { static_cast<i64>(n) };
        return;
    }

    pollards_rho_64::get_prime_factor(n);
    ranges::sort(ans);
}

i64 mul_mod(i128 a, i128 b, i128 mod)
{
    a %= mod;
    b %= mod;

    i128 res = (a * b) % mod;
    return (i64)res;
}

i64 pow_mod(i128 a, i128 n, i128 mod)
{
    i128 ans = 1;
    i128 powVal = a % mod;

    while (n)
    {
        if (n % 2 == 1)
        {
            ans = mul_mod(ans, powVal, mod);
        }

        powVal = mul_mod(powVal, powVal, mod);
        n >>= 1; // n /= 2
    }

    return (i64)ans;
}
