#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }

        sort(prices.begin(), prices.end());

        int max_sum = -1;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = prices[i] + prices[j];
                if (sum <= m) {
                    max_sum = max(max_sum, sum);
                } else {
                    break; 
                }
            }
        }

        if (max_sum == -1) {
            cout << "NONE" << endl;
        } else {
            cout << max_sum << endl;
        }
    }

    return 0;
}
