#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> winnings(n);
    int total = 0;


    for (int i = 0; i < n; ++i) {
        cin >> winnings[i];
        total += winnings[i];
    }


    if (total % 3 == 0) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
