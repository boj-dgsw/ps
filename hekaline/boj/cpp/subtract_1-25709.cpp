// implementation
// greedy
// Silver III

#include <bits/stdc++.h>

using namespace std;

void try_to_subtract(int& n);

int main()
{
    int n;
    cin >> n;

    int i = 0;
    while (n != 0)
    {
        i++;

        try_to_subtract(n);
    }

    cout << i;
}

void try_to_subtract(int &n)
{
    if (n == 1)
    {
        n = 0;
        return;
    }

    string n_str = to_string(n);

    for (int i = 0; i < n_str.length(); i++)
    {
        if (n_str[i] == '1')
        {
            string left = i == 0 ? "" : n_str.substr(0, i);
            string right = i == n_str.length() - 1 ? "" : n_str.substr(i + 1, string::npos);

            n = stoi(left + right);
            return;
        }
    }

    n -= 1;
}
