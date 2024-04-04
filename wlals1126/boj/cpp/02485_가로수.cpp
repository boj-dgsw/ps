#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (a <= b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> gap(N - 1);
    for (int i = 0; i < gap.size(); i++) {
        gap[i] = arr[i + 1] - arr[i];
    }
    for (int i = 1; i < gap.size(); i++) {
        gap[i] = GCD(gap[i], gap[i - 1]);
    }

    int result = gap[gap.size() - 1];

    cout << ((arr[N - 1] - arr[0]) / result - N + 1) << '\n';

    return 0;
}
