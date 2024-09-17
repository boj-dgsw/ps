#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> arr(4);

void count(char c, int sign) {
    switch (c) {
        case 'A':
            arr[0] += sign;
            break;
        case 'G':
            arr[1] += sign;
            break;
        case 'T':
            arr[2] += sign;
            break;
        case 'C':
            arr[3] += sign;
            break;
    }
}

int getKey() {
    return arr[0] + arr[1] * 600 + arr[2] * 600 * 600 + arr[3] * 600 * 600 * 600;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t-- > 0) {
        int k;
        string w;
        cin >> k >> w;

        for (int i = 0; i < k; i++) count(w[i], 1);

        unordered_map<int, int> map;
        map[getKey()] = 1;

        int max_count = 0, key, value;
        for (int i = 0; i < w.size() - k; i++) {
            count(w[i], -1);
            count(w[i + k], 1);

            key = getKey();
            value = map[key] + 1;
            map[key] = value;
            max_count = max(max_count, value);
        }

        cout << max_count << "\n";
    }

    return 0;
}
