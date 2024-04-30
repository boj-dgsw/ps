#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool flag = true;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'p') {
            if (i == S.length() - 1) {
                flag = false;
                break;
            }
            if (S[i + 1] != 'i') {
                flag = false;
                break;
            }
            i++;
        } else if (S[i] == 'k') {
            if (i == S.length() - 1) {
                flag = false;
                break;
            }
            if (S[i + 1] != 'a') {
                flag = false;
                break;
            }
            i++;
        } else if (S[i] == 'c') {
            if (i == S.length() - 1 || i == S.length() - 2) {
                flag = false;
                break;
            }
            if (S[i + 1] == 'h' && S[i + 2] == 'u') {
                i += 2;
            } else {
                flag = false;
                break;
            }
        } else {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
