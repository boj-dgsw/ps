// Bronze IV
// Implementation

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        ans += t >= a[i];
    }
    
    cout << ans;
}
