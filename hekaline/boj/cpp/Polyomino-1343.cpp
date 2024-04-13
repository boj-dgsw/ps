#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO

    string s;
    cin >> s;

    int xCount = 0;
    int sLen = s.length();
    for (int i = 0; i < sLen; i++)
    {
        if (s[i] == 'X')
        {
            xCount += 1;
            if (xCount >= 4)
            {
                s[i - 3] = s[i - 2] = s[i - 1] = s[i] = 'A';
                xCount = 0;
            }
        }
        else
        {
            if (xCount % 2 == 1)
            {
                cout << -1;
                return 0;
            }
            else
            {
                if (xCount == 2)
                {
                    s[i - 2] = s[i - 1] = 'B';
                    xCount = 0;
                }

            }
        }
    }
    if (xCount == 2)
        s[sLen - 2] = s[sLen - 1] = 'B';
    else if (xCount % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    cout << s;
}
