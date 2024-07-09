#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input1, input2;
    
    getline(cin, input1);
    getline(cin, input2);

    stringstream ss1(input1);
    stringstream ss2(input2);

    bool isWin = false;
    int j = 0, s = 0;

    for (int i = 0; i < 9; ++i) {
        int scoreJ, scoreS;
        ss1 >> scoreJ;
        ss2 >> scoreS;

        j += scoreJ;
        if (j > s) {
            isWin = true;
        }

        s += scoreS;
        if (j > s) {
            isWin = true;
        }
    }

    if (j < s && isWin) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
ㅇ
