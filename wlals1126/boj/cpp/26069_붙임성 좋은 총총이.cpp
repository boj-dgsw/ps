#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    unordered_set<string> hashSet;
    hashSet.insert("ChongChong");

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string A, B;
        ss >> A >> B;

        if (hashSet.count(A) || hashSet.count(B)) {
            hashSet.insert(A);
            hashSet.insert(B);
        }
    }

    cout << hashSet.size() << endl;
    return 0;
}
