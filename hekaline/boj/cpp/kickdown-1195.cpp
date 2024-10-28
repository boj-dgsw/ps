// implementation
// bruteforce
// Gold V

#include <bits/stdc++.h>

using namespace std;

bool is_index_valid(int i, int len)
{ return 0 <= i && i < len; }

int main()
{
    string a, b;
    cin >> a >> b;

    if (a.length() > b.length())
        swap(a, b);

    int origin_b_len = (int)b.length();
    int min_length = a.length() + b.length();
    b = string(a.length(), '0') + b + string(a.length(), '0');

    int max_idx = (int)b.length() - (int)a.length();
    for (int i = 0; i < max_idx; i++)
    {
        bool is_engaged = true;
        int zero_count = 0;

        for (int j = 0; j < (int)a.length(); j++)
        {
            if (a[j] == '2' && b[i + j] == '2')
            {
                is_engaged = false;
                break;
            }

            if (b[i + j] == '0')
                zero_count++;
        }

        if (is_engaged)
        {
            // cout << i << ' ' << zero_count << '\n';
            min_length = min(min_length, origin_b_len + zero_count);
        }
    }

    cout << min_length;
}
