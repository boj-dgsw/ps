#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    n %= 60;

    int arr[3] = {0, 0, 1};

    for (int i = 0; i < n; i++) {
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = (arr[0] + arr[1]) % 10;
    }

    cout << arr[2] << endl;
    return 0;
}
