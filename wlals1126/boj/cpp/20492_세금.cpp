#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    cout << static_cast<int>(N * 0.78) << " " << static_cast<int>((N * 0.8) + ((N * 0.2) * 0.78)) << endl;

    return 0;
}
