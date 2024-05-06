#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> perm(N);
    for (int i = 0; i < N; ++i) {
        cin >> perm[i];
    }

    if (prev_permutation(perm.begin(), perm.end())) {
        for (int i = 0; i < N; ++i) {
            cout << perm[i] << ' ';
        }
    } else {
        cout << -1;
    }

    return 0;
}
