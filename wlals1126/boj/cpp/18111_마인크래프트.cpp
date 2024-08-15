#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> mat(N, vector<int>(M));
    int max_height = 0;
    int min_height = 257;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
            max_height = max(max_height, mat[i][j]);
            min_height = min(min_height, mat[i][j]);
        }
    }

    int best_floor = min_height;
    int min_time = INT_MAX;

    for (int i = min_height; i <= max_height; i++) {
        int time = 0;
        int blocks = B;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int height_diff = mat[r][c] - i;
                if (height_diff > 0) {
                    time += 2 * height_diff;
                    blocks += height_diff;
                } else if (height_diff < 0) {
                    time -= height_diff;
                    blocks += height_diff;
                }
            }
        }

        if (blocks >= 0 && time <= min_time) {
            if (time == min_time) {
                best_floor = max(best_floor, i);
            } else {
                best_floor = i;
                min_time = time;
            }
        }
    }

    cout << min_time << " " << best_floor << endl;

    return 0;
}
