#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int tc = 1; tc <= n; ++tc) {
        int a;
        cin >> a;

        vector<int> arr1(5, 0);
        for (int i = 0; i < a; ++i) {
            int card;
            cin >> card;
            ++arr1[card];
        }

        int b;
        cin >> b;

        vector<int> arr2(5, 0);
        for (int i = 0; i < b; ++i) {
            int card;
            cin >> card;
            ++arr2[card];
        }

        for (int i = 4; i >= 1; --i) {
            if (arr1[i] != arr2[i]) {
                cout << (arr1[i] > arr2[i] ? "A" : "B") << '\n';
                break;
            } else if (i == 1) {
                cout << "D\n";
            }
        }
    }

    return 0;
}
