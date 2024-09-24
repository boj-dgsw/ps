#include <iostream>
using namespace std;

int main() {
    int w, h, p, q, t;
    
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    if (((p + t) / w) % 2 == 0) {
        p = (p + t) % (2 * w);
    } else {
        p = w - ((p + t) % (2 * w) - w);
    }

    if (((q + t) / h) % 2 == 0) {
        q = (q + t) % (2 * h);
    } else {
        q = h - ((q + t) % (2 * h) - h);
    }

    cout << p << " " << q << endl;

    return 0;
}
