#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, B;
    cin >> N >> K >> B;

    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    int startIndex = (B - 1) % N;

    int sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += sequence[(startIndex + i) % N];
    }

    cout << sum << endl;

    return 0;
}
