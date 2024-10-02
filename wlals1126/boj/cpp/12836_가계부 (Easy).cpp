#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> arr(N + 1, 0);

    while (Q--) {
        int temp, day;
        long long change;
        cin >> temp >> day >> change;

        if (temp == 1) {
            arr[day] += change;
        } else {
            long long sum = 0;
            for (int i = day; i <= change; i++) {
                sum += arr[i];
            }
            cout << sum << endl;
        }
    }

    return 0;
}
