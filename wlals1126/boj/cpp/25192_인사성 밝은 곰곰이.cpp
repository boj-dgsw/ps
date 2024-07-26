#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, bool> checkUser;
    int cnt = 0;
    bool flag = false;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;

        if (tmp == "ENTER") {
            checkUser.erase(checkUser.begin(), checkUser.end());
            flag = true;
            continue;
        }

        if (flag) {
            if (!checkUser[tmp]) {
                checkUser[tmp] = true; 
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
