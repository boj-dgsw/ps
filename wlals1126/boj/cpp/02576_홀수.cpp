#include <iostream>
using namespace std;

int main() {
    int min = 100;
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            sum += n;
            if (n < min) {
                min = n;
            }
        }
    }

    if (min == 100) {
        min = -1;
        cout << min << endl;
    } else {
        cout << sum << endl;
        cout << min << endl;
    }
    
    return 0;
}
