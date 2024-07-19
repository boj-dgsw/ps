#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<bool> arr(101, false);
        int temp, cnt = 0;

        ss >> temp;
        if (temp == -1)
            break;

        arr[temp] = true;
        while (ss >> temp) {
            arr[temp] = true;
        }

        for (int i = 1; i <= 50; i++) {
            if (arr[i] && arr[i * 2]) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
