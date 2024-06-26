#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, P, C;
    cin >> A >> P >> C;

    int max1 = A + C;

    int max2 = P;

    int maxPrize = max(max1, max2);

    cout << maxPrize << "\n";

    return 0;
}
ㅇ
