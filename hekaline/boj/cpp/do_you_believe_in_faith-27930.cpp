// string
// greedy
// Bronze I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

string s;

bool find_college()
{
    int i = 0;
    const string y = "YONSEI";
    const string k = "KOREA";

    int y_len = 0;
    int k_len = 0;

    for (char& c : s)
    {
        y_len++;
        if (c == y[i])
        {
            i++;
            if (i == 6)
            {
                break;
            }
        }
    }

    i = 0;

    for (char& c : s)
    {
        k_len++;
        if (c == k[i])
        {
            i++;
            if (i == 5)
            {
                break;
            }
        }
    }

    return k_len < y_len;
}

int main()
{
    FAST_IO;

    cin >> s;
    cout << (find_college() ? "KOREA" : "YONSEI");
}
