#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string A, B;
    cin >> A >> B;

    int sameIdxA = 0;
    int sameIdxB = 0;
    bool found = false;

    for (int i = 0; i < A.length(); i++) {
        char chA = A[i];
        for (int j = 0; j < B.length(); j++) {
            if (chA == B[j]) {
                sameIdxA = i;
                sameIdxB = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    vector<string> grid(B.length(), string(A.length(), '.'));

    for (int i = 0; i < A.length(); i++) {
        grid[sameIdxB][i] = A[i];
    }

    for (int i = 0; i < B.length(); i++) {
        grid[i][sameIdxA] = B[i];
    }

    for (const string& line : grid) {
        cout << line << endl;
    }

    return 0;
}
