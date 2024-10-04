#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int baseSum(int num, int base) {
    int sum = 0;
    while (num != 0) {
        sum += num % base;
        num /= base;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dsum;

    for (int base = 2; base <= n; ++base) {
        dsum.push_back({base, baseSum(n, base)});
    }

    sort(dsum.begin(), dsum.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    cout << dsum[0].second << " " << dsum[0].first << endl;

    return 0;
}
