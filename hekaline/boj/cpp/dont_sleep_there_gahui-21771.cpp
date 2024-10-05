// implementation
// string

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int rg, rp, cg, cp;
    cin >> rg >> cg >> rp >> cp;

    int pillow_sum(0);

    for (int i = 0; i < r; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < c; j++)
        {
            if (temp[j] == 'P')
                pillow_sum++;
        }
    }

    cout << (pillow_sum != rp * cp);
}
