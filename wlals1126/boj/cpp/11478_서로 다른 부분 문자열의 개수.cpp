#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    unordered_set<string> subStrig;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j <= s.length(); ++j) {
            subStrig.insert(s.substr(i, j - i));
        }
    }

    cout << subStrig.size() << endl;
    return 0;
}
