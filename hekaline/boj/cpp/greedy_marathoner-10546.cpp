// hash
// data structures
// Silver IV

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO\
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    unordered_set<string> names;

    for (int i = 0; i < n * 2 - 1; i++)
    {
        string name;
        cin >> name;

        if (names.contains(name))
        {
            names.erase(name);
        } else
        {
            // new name
            names.insert(name);
        }
    }

    cout << *names.begin();
}
