// stack
// string
// data structures
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

constexpr short OPEN = -1;
constexpr short CLOSE = -2;
constexpr short NUMBER = 0;

short charToShort(const char& numChar)
{
    return numChar - '0';
}

short atomToShort(const char& atom)
{
    switch (atom)
    {
        case 'H': return 1;
        case 'C': return 12;
        case 'O': return 16;
        case '(': return OPEN;
        case ')': return CLOSE;
        default: return NUMBER;
    }
}

int main()
{
    FAST_IO;

    string s;
    cin >> s;

    int sLen = s.length();
    vector<short> _stack;

    int ans = 0;

    for (int i = 0; i < sLen; i++)
    {
        char currAtom = s[i];
        short atomAsShort = atomToShort(currAtom);

        if (atomAsShort == NUMBER)
        {
            // 숫자
            // 스택 맨 위의 수에 곱함
            int back = _stack.back(); _stack.pop_back();
            _stack.emplace_back(back * charToShort(currAtom));

            continue;
        }

        // 닫는 문자열
        if (atomAsShort == CLOSE)
        {
            // 괄호 내에 있는 분자의 화학식량
            short moleculeWeight = 0;

            // OPEN이 나올 때까지 모두 빼냄
            while (true)
            {
                short val = _stack.back(); _stack.pop_back();
                if (val == OPEN) break;

                moleculeWeight += val;
            }

            _stack.push_back(moleculeWeight);
            continue;
        }

        // 여는 괄호 또는 원소는 push
        _stack.push_back(atomAsShort);

    } // end of for

    // 스택에 있는 수 모두 더하기
    while (!_stack.empty())
    {
        ans += _stack.back();
        _stack.pop_back();
    }

    cout << ans;
}
