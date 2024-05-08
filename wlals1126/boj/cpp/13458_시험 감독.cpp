#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<int> a;
long long ans;

int main() {
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> B >> C;
    for(int i = 0; i < N; i++) {
        a[i] = a[i] - B < 0 ? 0 : a[i] - B;
        int cnt = (a[i] + C - 1) / C;
        ans += (long long)cnt + 1;
    }
    cout << ans << endl;
    return 0;
}
