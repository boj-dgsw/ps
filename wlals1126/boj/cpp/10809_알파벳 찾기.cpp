#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> apb(26, -1);

    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (apb[str[i] - 'a'] == -1) {
            apb[str[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << apb[i] << " ";
    }
    cout << endl;

    return 0;
}
