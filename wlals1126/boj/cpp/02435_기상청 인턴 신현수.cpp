#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int days, length;
    cin >> days >> length;

    vector<int> temp(days);
    vector<int> calc(days - length + 1, 0);

    for (int i = 0; i < days; ++i) {
        cin >> temp[i];
    }

    for (int i = 0; i < calc.size(); ++i) {
        for (int j = i; j < i + length; ++j) {
            calc[i] += temp[j];
        }
    }

    cout << *max_element(calc.begin(), calc.end()) << endl;

    return 0;
}
