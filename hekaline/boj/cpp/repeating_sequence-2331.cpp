// math
// implementation

#include <bits/stdc++.h>

using namespace std;

bool visited[236197] = { false, };
int a, p;

int convert(int val)
{
    int res = 0;

    while (val != 0)
    {
        res += (int)pow(val % 10, p);
        val /= 10;
    }

    return res;
}

int find_cycle_cnt()
{
    int i = 0;
    for (; visited[a] == true; i++)
    {
        visited[a] = false;
        a = convert(a);
    }

    return i;
}

int main()
{
    cin >> a >> p;

    for (long long i = 0;; i++)
    {
        if (visited[a] == true)
        {
            cout << i - find_cycle_cnt();
            return 0;
        }

        visited[a] = true;
        a = convert(a);
    }
}
