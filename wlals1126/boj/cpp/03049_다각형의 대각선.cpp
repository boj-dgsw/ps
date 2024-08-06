#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 1;
    for (int i = 1; i <= 4; i++) {
        result *= n - i + 1;
        result /= i;
    }

    cout << result << endl;

    return 0;
}
