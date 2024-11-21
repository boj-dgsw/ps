// bruteforce
// implementation
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

vector<pair<pair<int, int>, int>> arr; // { { x, y }, energy }
vector<int> energies;

istream& operator>>(istream& is, pair<pair<int, int>, int>& target)
{
    is >> target.first.first >> target.first.second >> target.second;

    return is;
}

int get_power(int ox, int oy, int energy, int tx, int ty)
{
    return max(0, energy - abs(ox - tx) - abs(oy - ty));
}

int get_power(pair<pair<int, int>, int> o, pair<int, int> t)
{
    return get_power(o.first.first, o.first.second, o.second, t.first, t.second);
}



int main()
{
    FAST_IO

    int n;
    cin >> n;

    arr.resize(n + 1);
    energies.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        energies[i] = get_power(arr[0], arr[i].first);
    }

    int max_power = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            energies[j] -= get_power(arr[i], arr[j].first);
        }
    }

    max_power = max(0, *ranges::max_element(energies));

    if (max_power == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << max_power;
}
