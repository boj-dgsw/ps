#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B;
    C.reserve(A.size() * 2);
    for (int i = 0; i < A.length(); i++) {
        C += A[i];
        C += B[i];
    }
    while (C.length() > 2) {
        string D;
        for (int i = 0; i < C.length() - 1; i++) {
            char sum = ((C[i] - '0') + (C[i + 1] - '0')) % 10 + '0';
            D.push_back(sum);
        }
        C = D;
    }
    cout << C << endl;

    return 0;
}
