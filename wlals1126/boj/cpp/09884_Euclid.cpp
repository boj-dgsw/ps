#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    while (A != B) {
        if (A > B) {
            A = A - B;
        } else {
            B = B - A;
        }
    }

    cout << A << '\n';

    return 0;
}
