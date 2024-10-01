#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int count = 0;

    if (T == 1 || T == 2 || T == 4) {
        cout << 0 << endl;
    } else { 
        for (int i = 1; i <= T / 3; i++) {
            int sum = T - i;
            for (int j = i; j <= sum / 2; j++) {
                int s = sum - j;
                if (s < j + i) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
