#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1;
    bool continuous_c = false;
    bool continuous_d = false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'c') {
            if (!continuous_c) 
                ans *= 26;
            else 
                ans *= 25;
            continuous_c = true;
            continuous_d = false;
        } else if (c == 'd') {
            if (!continuous_d) 
                ans *= 10;
            else 
                ans *= 9;
            continuous_c = false;
            continuous_d = true;
        }
    }
    if (s.length() == 0) 
        ans = 0;
    cout << ans << endl;
    return 0;
}
