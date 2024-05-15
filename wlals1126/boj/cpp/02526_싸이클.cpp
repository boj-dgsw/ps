#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> index_map;
    int current = n;
    int step = 0;

    while (true) {
        if (index_map.find(current) != index_map.end()) {
            cout << step - index_map[current] << endl;
            break;
        } else {
            index_map[current] = step;
            current = (current * n) % m;
            step++;
        }
    }

    return 0;
}
