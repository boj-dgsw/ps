// stack
// data structures
// implementation
// Gold IV

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr int ERR_VAL = -2147483648;

bool isOverflowed(int n) { return abs(n) > (int)1e9; }
bool isMultiplyWillOverflow(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return false;
    }

    if (abs(a) > INT_MAX / abs(b))
        return true;

    return isOverflowed(a * b);
}

void addCommand(string& cmd);
int execute(int v);

vector<string> cmdArr;

int main()
{
    FAST_IO;
    while (true)
    {
        string cmd;
        getline(cin, cmd);

        if (cmd == "QUIT")
        {
            break;
        }

        if (cmd.empty())
        {
            // 빈 줄을 입력받음
            continue;
        }

        if (cmd == "END")
        {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                // 초기 숫자 입력받고 명령어 전부 실행
                int v;
                cin >> v;

                int ans = execute(v);
                cout << (ans == ERR_VAL ? "ERROR" : to_string(ans)) << '\n';
            }

            cmdArr.clear();
            cout << '\n';
        }
        else
        {
            addCommand(cmd);
        }
    }
}

int execute(int v)
{
    vector<int> indexed_stack;
    indexed_stack.push_back(v);

    int cmdLen = cmdArr.size();
    for (int i = 0; i < cmdLen; i++)
    {
        string cmd = cmdArr[i];

        if (cmd == "NUM")
        {
            int x = stoi(cmdArr[++i]);
            indexed_stack.push_back(x);
        } else if (cmd == "POP")
        {
            if (indexed_stack.empty())
                return ERR_VAL;

            indexed_stack.pop_back();
        } else if (cmd == "INV")
        {
            if (indexed_stack.empty())
                return ERR_VAL;

            indexed_stack.back() *= -1;
        } else if (cmd == "DUP")
        {
            if (indexed_stack.empty())
                return ERR_VAL;

            indexed_stack.push_back(indexed_stack.back());
        } else if (cmd == "SWP")
        {
            if (indexed_stack.size() < 2)
                return ERR_VAL;

            int& firstVal = indexed_stack.back();
            int& secondVal = indexed_stack[indexed_stack.size() - 2];

            swap(firstVal, secondVal);
        } else if (cmd == "ADD")
        {
            if (indexed_stack.size() < 2)
                return ERR_VAL;

            indexed_stack[indexed_stack.size() - 2] += indexed_stack.back();
            indexed_stack.pop_back();

            if (isOverflowed(indexed_stack.back()))
                return ERR_VAL;
        } else if (cmd == "SUB")
        {
            if (indexed_stack.size() < 2)
                return ERR_VAL;

            indexed_stack[indexed_stack.size() - 2] -= indexed_stack.back();
            indexed_stack.pop_back();

            if (isOverflowed(indexed_stack.back()))
                return ERR_VAL;
        } else if (cmd == "MUL")
        {
            if (indexed_stack.size() < 2)
                return ERR_VAL;

            int a = indexed_stack.back();
            int b = indexed_stack[indexed_stack.size() - 2];

            if (isMultiplyWillOverflow(a, b))
                return ERR_VAL;

            indexed_stack.pop_back();
            indexed_stack.pop_back();
            indexed_stack.push_back(a * b);

            if (isOverflowed(indexed_stack.back()))
                return ERR_VAL;
        } else if (cmd == "DIV")
        {
            if (indexed_stack.size() < 2 || indexed_stack.back() == 0)
                return ERR_VAL;

            indexed_stack[indexed_stack.size() - 2] /= indexed_stack.back();
            indexed_stack.pop_back();

            if (isOverflowed(indexed_stack.back()))
                return ERR_VAL;
        } else if (cmd == "MOD")
        {
            if (indexed_stack.size() < 2 || indexed_stack.back() == 0)
                return ERR_VAL;

            indexed_stack[indexed_stack.size() - 2] %= indexed_stack.back();
            indexed_stack.pop_back();

            if (isOverflowed(indexed_stack.back()))
                return ERR_VAL;
        }
    }

    if (indexed_stack.size() != 1)
    {
        return ERR_VAL;
    }
    return indexed_stack.back();
}


void addCommand(string& cmd)
{
    stringstream ss(cmd);
    ss >> cmd; // rewrite cmd(seperate possible integer)

    cmdArr.push_back(cmd);

    if (cmd == "NUM")
    {
        string numToStr;
        ss >> numToStr;

        cmdArr.push_back(numToStr);
    }
}
