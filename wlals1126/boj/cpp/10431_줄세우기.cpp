#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int t;
        cin >> t;

        vector<int> arr;
        int result = 0;

        for (int j = 0; j < 20; j++) {
            int num;
            cin >> num;

            if (j == 0) {
                arr.push_back(num);
            } else {
                bool flag = false;

                for (int k = 0; k < j; k++) {
                    if (arr[k] > num) {
                        result += (j - k);
                        flag = true;
                        break;
                    }
                }
                arr.push_back(num);
                if (flag) {
                    sort(arr.begin(), arr.end());
                }
            }
        }
        cout << t << " " << result << '\n';
    }

    return 0;
}
