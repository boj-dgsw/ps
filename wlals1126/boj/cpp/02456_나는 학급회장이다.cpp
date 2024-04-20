#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> scoreList(N, vector<int>(3));
    int A = 0, aScore = 0, B = 0, bScore = 0, C = 0, cScore = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> scoreList[i][j];
            if (j == 0) {
                A += scoreList[i][j];
                aScore += scoreList[i][j] * scoreList[i][j];
            } else if (j == 1) {
                B += scoreList[i][j];
                bScore += scoreList[i][j] * scoreList[i][j];
            } else {
                C += scoreList[i][j];
                cScore += scoreList[i][j] * scoreList[i][j];
            }
        }
    }

    if (aScore == bScore && bScore == cScore) {
        cout << "0 " << A << endl;
    } else if (aScore > bScore && aScore > cScore) {
        cout << "1 " << A << endl;
    } else if (bScore > aScore && bScore > cScore) {
        cout << "2 " << B << endl;
    } else if (cScore > aScore && cScore > bScore) {
        cout << "3 " << C << endl;
    } else if (aScore == bScore || aScore == cScore) {
        cout << "0 " << A << endl;
    } else if (bScore == cScore) {
        cout << "0 " << B << endl;
    }

    return 0;
}
