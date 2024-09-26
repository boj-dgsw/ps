#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int tot = m * k;  
    int ans = 0;     
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());  
    
    for (int i = n - 1; i >= 0; i--) {
        if (tot <= 0) {
            break;
        } else {
            tot -= arr[i];
            ans++;  
        }
    }
    
    if (tot > 0) {
        cout << "STRESS" << endl;
    } else {
        cout << ans << endl;  
    }

    return 0;
}
