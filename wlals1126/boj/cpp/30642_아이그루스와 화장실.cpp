#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    string mascot;
    
    cin >> N >> mascot >> K;

    bool isLarge = (mascot == "annyong");
    int closestFloor;

    if (isLarge) {
        closestFloor = (K % 2 == 1) ? K : (K + 1 <= N ? K + 1 : K - 1);
    } else {
        closestFloor = (K % 2 == 0) ? K : (K + 1 <= N ? K + 1 : K - 1);
    }

    cout << closestFloor << endl;
    return 0;
}
