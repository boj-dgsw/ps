#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int step, mod;
    
    while (cin >> step >> mod) {
        if (gcd(step, mod) == 1) {
            cout << setw(10) << step << setw(10) << mod << ' ' << "Good Choice" << endl;
        } else {
            cout << setw(10) << step << setw(10) << mod << ' ' << "Bad Choice" << endl;
        }
        cout << endl; 
    }

    return 0;
}
