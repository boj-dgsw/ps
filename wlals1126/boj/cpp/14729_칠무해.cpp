#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    vector<double> list(cnt);

    for (int i = 0; i < cnt; i++) {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    for (int i = 0; i < 7; i++) {
        printf("%.3f\n", list[i]);
    }

    return 0;
}
