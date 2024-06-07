#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;
    C = C % 2;
    
    for (int i = 0; i < C; i++) {
        A = A ^ B;
    }
    
    cout << A << endl;
    
    return 0;
}
