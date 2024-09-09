#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, L;
        cin >> N >> L;

        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
        }

        sort(p.begin(), p.end());

        int solved = 0, last = 0, total = 0, time = 0;

        for (int i = 0; i < N; i++) {
            if (time + p[i] <= L) {
                time += p[i];
                total += time;
                last = time;
                solved++;
            } else {
                break;
            }
        }

        cout << "Case " << t << ": " << solved << " " << last << " " << total << endl;
    }

    return 0;
}
