#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;

    vector<vector<int>> map(1001, vector<int>(1001, 0));

    for (int i = 0; i < num; i++) {
        int x, y, width, height;
        cin >> x >> y >> width >> height;

        for (int k = y; k < y + height; k++) {
            for (int j = x; j < x + width; j++) {
                map[k][j] = i + 1;
            }
        }
    }

    int cnt = 0;
    int size = 1;
    
    while (size <= num) {
        int count = 0;
        for (int k = 0; k < 1001; k++) {
            for (int j = 0; j < 1001; j++) {
                if (map[k][j] == size) {
                    count++;
                } else if (map[k][j] == 0) {
                    cnt++;
                }
            }
        }
        cout << count << endl;
        size++;
    }
    if (cnt == 1001*1001) {
        cout << 0 << endl;
    }
    return 0;
}
