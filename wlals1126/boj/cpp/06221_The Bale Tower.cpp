#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bale {
    int width, breadth;
};

bool compare(const Bale &a, const Bale &b) {
    if (a.width == b.width) {
        return a.breadth < b.breadth;
    }
    return a.width < b.width;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<Bale> bales(N);
    for (int i = 0; i < N; ++i) {
        cin >> bales[i].width >> bales[i].breadth;
    }

    sort(bales.begin(), bales.end(), compare);

    vector<int> dp(N, 1);

    int max_height = 1;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (bales[i].width > bales[j].width && bales[i].breadth > bales[j].breadth) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_height = max(max_height, dp[i]);
    }

    cout << max_height << endl;

    return 0;
}
