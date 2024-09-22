#include <iostream>
using namespace std;

int nimSum(int B, int X, int Y) {
    int result = 0, place = 1;

    while (X > 0 || Y > 0) {
        int xDigit = X % B; 
        int yDigit = Y % B; 
        int sum = (xDigit + yDigit) % B;

        result += sum * place; 
        place *= B; 

        X /= B; 
        Y /= B; 
    }

    return result;
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int B, X, Y;
        cin >> B >> X >> Y;
        cout << nimSum(B, X, Y) << endl;
    }

    return 0;
}
