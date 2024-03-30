#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> mt(n);
    for(int i = 0; i < n; ++i) {
        cin >> mt[i];
    }

    int ans = 0, tmp = 0, high = 0;
    for(int i = 0; i < n; ++i) {
        if(mt[i] > high) {
            high = mt[i];
            tmp = 0;
        }
        else {
            tmp++;
        }
        ans = max(ans, tmp);
    }

    cout << ans << "\n";

    return 0;
}
