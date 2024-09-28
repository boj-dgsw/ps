#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string original[N];
    string expanded[N];

    for (int i = 0; i < N; i++) {
        cin >> original[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> expanded[i];
    }

    bool isEyfa = true;

    for (int i = 0; i < N && isEyfa; i++) {
        for (int j = 0; j < M; j++) {
            if (original[i][j] != expanded[i][2 * j] || original[i][j] != expanded[i][2 * j + 1]) {
                isEyfa = false;
                break;
            }
        }
    }

    if (isEyfa) {
        cout << "Eyfa" << endl;
    } else {
        cout << "Not Eyfa" << endl;
    }

    return 0;
}
