#include <iostream>
#include <bits/stdc++.h>
#define OUT
#define IN const

using namespace std;

constexpr char SUBTRACT = 'S';
constexpr char MULTIPLY = 'M';
constexpr char DIVIDE = 'U';
constexpr char PLUS = 'P';
constexpr char CONSEQUENCE = 'C';
const string NO_MORE_NUMBER = "NULL";

[[nodiscard]]
bool isNumber(char c) { return '0' <= c && c <= '9'; }

[[nodiscard]]
string getNumberFrom(OUT int &startFrom, IN string &s);

int main()
{
    int n;
    bool printed = false;
    cin >> n;

    vector<string> stack;
    string s;
    cin >> s;

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        char currC = s[i];
        if (isNumber(currC))
        {
            stack.push_back(getNumberFrom(i, s));
        }
        else
        {
            if (currC == CONSEQUENCE)
            {
                cout << stack.back() << ' ';
                printed = true;
                continue;
            }

            string firstStr = stack.back(); stack.pop_back();
            ++i;
            string secondStr = getNumberFrom(i, s);
            if (secondStr == NO_MORE_NUMBER)
            {
                break;
            }

            int firstNum = stoi(firstStr);
            int secondNum = stoi(secondStr);

            switch (currC)
            {
                case SUBTRACT:
                    stack.push_back(to_string(firstNum - secondNum));
                    break;
                case MULTIPLY:
                    stack.push_back(to_string(firstNum * secondNum));
                    break;
                case DIVIDE:
                    stack.push_back(to_string(firstNum / secondNum));
                    break;
                case PLUS:
                    stack.push_back(to_string(firstNum + secondNum));
                    break;
                default:
                    break;
            }
        } // end of else

    } // end of for

    if (!printed)
    {
        cout << "NO OUTPUT";
    }
}

string getNumberFrom(OUT int &startFrom, IN string& s)
{
    int len = s.length();

    while (startFrom < len)
    {
        if (isNumber(s[startFrom]))
            break;

        startFrom++;
    }

    string temp(1, s[startFrom]);

    while (startFrom < len - 1)
    {
        if (!isNumber(s[startFrom + 1]))
        {
            break;
        }

        if (!temp.empty() || s[startFrom + 1] != '0')
        {
            temp += s[++startFrom];
        }
    }

    try
    {
        temp = to_string(stoi(temp)); // stoi로 0 제거 후 스택에 넣기
    } catch (exception& e)
    {
        return NO_MORE_NUMBER;
    }
    return temp;
}
