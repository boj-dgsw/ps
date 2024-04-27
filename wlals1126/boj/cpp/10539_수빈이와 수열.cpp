#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] * (i + 1) - sum;
        sum += b[i];
    }

    for (int j : b) {
        cout << j << " ";
    }

    return 0;
}
수빈이와 수열
