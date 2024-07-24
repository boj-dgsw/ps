#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = INT_MAX, sum = 0, lo = 0, hi = 0;
    while (true) {
        if (sum >= S) {
            sum -= arr[lo++];
            result = min(result, hi - lo + 1);
        } else if (hi == N) {
            break;
        } else {
            sum += arr[hi++];
        }
    }

    if (result == INT_MAX) {
        cout << 0 << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
