#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

#define OUT
#define IN const

using namespace std;
using ll = long long;

constexpr char SUBTRACT = 'S';
constexpr char MULTIPLY = 'M';
constexpr char DIVIDE = 'U';
constexpr char PLUS = 'P';
constexpr char CONSEQUENCE = 'C';
constexpr ll NO_MORE_NUMBER = LLONG_MAX;

[[nodiscard]]
bool isNumber(char c) { return '0' <= c && c <= '9'; }

[[nodiscard]]
ll getNumFrom(OUT int &startFrom, IN string &s);

int main()
{
    int n;
    bool printed = false;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            ans = getNumFrom(i, s);
            continue;
        }

        char currC = s[i];
        if (currC == CONSEQUENCE)
        {
            cout << ans << ' ';
            printed = true;
            continue;
        }

        ++i; // 알파벳 건너뛰기
        ll secondNum = getNumFrom(i, s);
        if (secondNum == NO_MORE_NUMBER)
        {
            break;
        }

        switch (currC)
        {
            case SUBTRACT:
                ans -= secondNum;
                break;
            case MULTIPLY:
                ans *= secondNum;
                break;
            case DIVIDE:
                ans /= secondNum;
                break;
            case PLUS:
                ans += secondNum;
                break;
            default:
                break;
        }

    } // end of for

    if (!printed)
    {
        cout << "NO OUTPUT";
    }
}

ll getNumFrom(OUT int &startFrom, IN string& s)
{
    int len = s.length();
    if (startFrom >= len)
    {
        return NO_MORE_NUMBER;
    }

    ll temp = s[startFrom] - '0';

    while (startFrom + 1 < len)
    {
        if (!isNumber(s[startFrom + 1]))
        {
            break;
        }

        if (temp != 0 || s[startFrom + 1] != '0')
        {
            temp *= 10;
            temp += s[startFrom + 1] - '0';
        }

        startFrom++;
    }

    return temp;
}
