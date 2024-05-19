#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> arr(N);

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        arr[i] = stoll(s);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
