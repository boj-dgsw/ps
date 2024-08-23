// Silver V
// Sort

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using pss = pair<string, string>;


bool cmp(const pss& a, const pss& b)
{
    int val = a.first.compare(b.first);
    if (val != 0) return val < 0;
    
    return a.second.compare(b.second) > 0;
}

int main()
{
    FAST_IO;
    
    int n;
    cin >> n;
    vector<pss> arr(n);
    
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}
