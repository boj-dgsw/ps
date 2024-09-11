#include <iostream>
using namespace std;

int main() {
    int R, S;
    cin >> R >> S;

    int total_cupcakes = R * 8 + S * 3;
    int leftover = total_cupcakes - 28;

    cout << leftover << endl;
    
    return 0;
}
