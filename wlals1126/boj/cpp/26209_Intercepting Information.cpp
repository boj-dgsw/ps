#include <iostream>

using namespace std;

int main() {
    int bits[8];
    bool success = true;

    for (int i = 0; i < 8; ++i) {
        cin >> bits[i];
        if (bits[i] == 9) {
            success = false;
        }
    }

    if (success) {
        cout << "S" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}
