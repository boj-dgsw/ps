#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    cin >> num;
    vector<string> strs(num);

    for (int i = 0; i < num; ++i) {
        cin >> strs[i];
    }

    int length = strs[0].length();

    for (int i = 0; i < length; ++i) {
        unordered_set<string> unique_substrings;
        bool is_unique = true;

        for (int j = 0; j < num; ++j) {
            string tmp = strs[j].substr(length - i - 1, i + 1);

            if (unique_substrings.find(tmp) == unique_substrings.end()) {
                unique_substrings.insert(tmp);
            } else {
                is_unique = false;
                break;
            }
        }

        if (is_unique && unique_substrings.size() == num) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
