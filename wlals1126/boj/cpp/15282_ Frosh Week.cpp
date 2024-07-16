#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> t(n); 
    vector<int> l(m);

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }

    sort(t.begin(), t.end());
    sort(l.begin(), l.end());

    int ti = 0; 
    int li = 0; 
    int count = 0; 

    while (ti < n && li < m) {
        if (t[ti] <= l[li]) {
            ++count;
            ++ti;
        }
        ++li;
    }

    cout << count << endl;

    return 0;
}
1
