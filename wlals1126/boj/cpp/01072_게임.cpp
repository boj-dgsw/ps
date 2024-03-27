#include <iostream>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    int z = int(y * 100 / x);
    int left = 0; 
    int right = x + 1; 
    int ans = -1; 

    while (left <= right) {
        int mid = (left + right) / 2;
        int tmp = int((y + mid) * 100 / (x + mid));

        if (tmp > z) {
            right = mid - 1;
            ans = mid; 
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}
