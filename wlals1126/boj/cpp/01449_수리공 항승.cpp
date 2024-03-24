#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<double> holes;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        holes.push_back(x - 0.5);
        holes.push_back(x + 0.5);
    }

    sort(holes.begin(), holes.end());

    double temp = holes[0];
    int result = 1;
    bool flag = false;

    for (int i = 1; i < holes.size(); i++) {
        if (temp + l > holes[i]) {
            continue;
        } else if (!flag && temp + l == holes[i]) {
            flag = true;
            continue;
        } else {
            temp = holes[i];
            result += 1;
            flag = false;
        }
    }

    cout << result << endl;
    
    return 0;
}
