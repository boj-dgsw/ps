#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int ans = 0;
    int cnt = 0;

    while (cnt < K) {
        ans += pq.top();
        pq.pop();
        cnt++;
    }

    ans -= ((K - 1) * K / 2);

    cout << ans << endl;

    return 0;
}
