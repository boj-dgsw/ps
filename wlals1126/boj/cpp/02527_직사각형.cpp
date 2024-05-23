#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 4; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if((x2 == x3 || x1 == x4) && (y2 == y3 || y1 == y4)) {
            cout << "c" << endl;
        }
        else if((x2 < x3) || (x1 > x4) || (y2 < y3) || (y1 > y4)) {
            cout << "d" << endl;
        }
        else if((y2 == y3) || (y1 == y4) || (x2 == x3) || (x1 == x4)) {
            cout << "b" << endl;
        }
        else {
            cout << "a" << endl;
        }
    }
    return 0;
}
