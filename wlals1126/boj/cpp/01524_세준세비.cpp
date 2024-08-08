#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N, M;
        cin >> N >> M;
        
        int sMax = INT_MIN;
        int bMax = INT_MIN;

        for (int j = 0; j < N; j++) {
            int s;
            cin >> s;
            sMax = max(sMax, s);
        }

        for (int j = 0; j < M; j++) {
            int b;
            cin >> b;
            bMax = max(bMax, b);
        }

        if (N == 0 && M == 0) {
            cout << "C" << endl;
            continue;
        }

        if (sMax >= bMax) {
            cout << "S" << endl;
        } else {
            cout << "B" << endl;
        }
    }

    return 0;
}
