// dp
// Bronze I

#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> calls(n + 1);
    calls[1] = calls[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        calls[i] = calls[i - 1] + calls[i - 2];
    }

    std::cout << calls[n] << ' ' << n - 2;
}
