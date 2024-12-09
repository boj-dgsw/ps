// sieve
// prefix sum
// bruteforcing
// mathematics
// number theory
// primality test
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

class Sieve
{
public:
    Sieve() = delete;
    explicit Sieve(int max_n)
    {
        init(max_n);
    }

    bool is_prime(int at)
    {
        if (at < 0 || at >= is_prime_arr.size())
        {
            return false;
        }

        return is_prime_arr[at];
    }

    const std::vector<int> &get_primes()
    {
        return primes;
    }

private:
    void init(int max_n)
    {
        max_n = std::max(max_n, 2);

        is_prime_arr.resize(max_n + 1, true);
        is_prime_arr[0] = is_prime_arr[1] = false;

        for (int i = 2; i <= max_n; i++)
        {
            if (!is_prime_arr[i]) continue;

            primes.emplace_back(i);
            for (int j = i * 2; j <= max_n; j += i)
            {
                is_prime_arr[j] = false;
            }
        }
    }

    std::vector<bool> is_prime_arr;
    std::vector<int> primes;
};

int main()
{
    FAST_IO

    int n;
    std::cin >> n;

    Sieve sieve = Sieve(2'000 * 500);
    std::vector<int> sum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int ans = 0;
    for (const int &prime : sieve.get_primes())
    {
        //std::cout << prime;
        if (prime > n) break;
        for (int i = 1; i <= n - prime + 1; i++)
        {
            if (sieve.is_prime(sum[i + prime - 1] - sum[i - 1]))
            {
                ans += 1;
            }
        }
    }

    std::cout << ans;
}
