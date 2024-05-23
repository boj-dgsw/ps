#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int line[6]; 
    
    int maxW = 0;
    int maxH = 0;
    int cutW = 0;
    int cutH = 0;
    
    for (int i = 0; i < 6; i++) {
        int direction; 
        cin >> direction >> line[i];
    }

    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            maxW = max(maxW, line[i]);
        } else {
            maxH = max(maxH, line[i]);
        }
    }

    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            if (maxH == line[(i + 5) % 6] + line[(i + 1) % 6]) {
                cutW = line[i];
            }
        } else {
            if (maxW == line[(i + 5) % 6] + line[(i + 1) % 6]) {
                cutH = line[i];
            }
        }
    }

    cout << (maxW * maxH - cutW * cutH) * K << endl;

    return 0;
}
