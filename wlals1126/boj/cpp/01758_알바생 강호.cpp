#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> tips(N);
    for (int i = 0; i < N; ++i) {
        cin >> tips[i];
    }

    sort(tips.begin(), tips.end(), greater<int>());

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int tip = tips[i] - (i + 1 - 1);
        if (tip <= 0) {
            break;
        }
        sum += tip;
    }
    cout << sum << endl;

    return 0;
}
