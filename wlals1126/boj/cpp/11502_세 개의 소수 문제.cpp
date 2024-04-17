#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
        {
            primes.push_back(p);
        }
    }

    return primes;
}

vector<int> expressPrimes(int n, const vector<int> &primes)
{
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i; j < primes.size(); j++)
        {
            for (int k = j; k < primes.size(); k++)
            {
                if (primes[i] + primes[j] + primes[k] == n)
                {
                    return {primes[i], primes[j], primes[k]};
                }
            }
        }
    }
    return {};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes = getPrimes(1000);

    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;

        if (K < 7 || K % 2 == 0)
        {
            cout << "0\n";
            continue;
        }

        vector<int> result = expressPrimes(K, primes);
        if (!result.empty())
        {
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}
