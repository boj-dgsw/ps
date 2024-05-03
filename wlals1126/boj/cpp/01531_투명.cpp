#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> picture;

void mosaic(int lx, int ly, int rx, int ry) {
    for (int i = lx; i <= rx; i++) {
        for (int j = ly; j <= ry; j++) {
            picture[i][j]++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    picture.assign(101, vector<int>(101, 0));

    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        mosaic(lx, ly, rx, ry);
    }

    int result = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (picture[i][j] > M) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
