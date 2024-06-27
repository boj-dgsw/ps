#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string bin1, bin2;
        cin >> bin1 >> bin2;  

        int hammingDistance = 0;
        for (size_t i = 0; i < bin1.size(); ++i) {
            if (bin1[i] != bin2[i]) {
                hammingDistance++;
            }
        }

        cout << "Hamming distance is " << hammingDistance << "." << endl;
    }

    return 0;
}
