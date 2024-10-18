// implementation
// Silver V

#include <bits/stdc++.h>

using namespace std;

bool is_index_valid(int idx, int n)
{ return 0 <= idx && idx < n; }

int main()
{
    int n, curr, prev;

    while (true)
    {
        cin >> n;
        if (cin.eof()) break;

        vector<bool> arr(n);
        bool is_jolly = true;

        cin >> prev;
        for (int i = 1; i < n; i++)
        {
            cin >> curr;
            int diff = abs(prev - curr);

            if (!is_index_valid(diff, n) || arr[diff] == true)
            {
                is_jolly = false;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            arr[diff] = true;
            prev = curr;
        }

        cout << (is_jolly ? "Jolly" : "Not jolly") << '\n';
    }
}
