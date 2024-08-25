#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long k = 1000000000000; 

    long long factorial = 1;
    for (int i = 2; i <= N; i++) {
        factorial *= i;
        while (factorial % 10 == 0) {
            factorial /= 10;
        }
        factorial %= k;
    }

    factorial %= 100000; 

    cout << setw(5) << setfill('0') << factorial << endl;

    return 0;
}
