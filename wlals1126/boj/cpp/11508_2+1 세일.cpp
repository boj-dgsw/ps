#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end(), greater<int>());

    int totalCost = 0;
    for (int i = 0; i < N; ++i) {
        if ((i + 1) % 3 == 0) {
            continue;
        }
        totalCost += prices[i];
    }

    cout << totalCost << endl;

    return 0;
}
