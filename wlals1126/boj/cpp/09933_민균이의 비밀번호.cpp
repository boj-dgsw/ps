#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); 

    unordered_set<string> arr;
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        arr.insert(tmp);
        
        string reversed_tmp = tmp;
        reverse(reversed_tmp.begin(), reversed_tmp.end());

        if (arr.find(reversed_tmp) != arr.end()) {
            cout << tmp.length() << " " << tmp[tmp.length() / 2] << endl;
        }
    }

    return 0;
}
