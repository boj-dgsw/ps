#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    vector<pair<string, int>> namelist;
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        namelist.emplace_back(name, score);
    }

    sort(namelist.begin(), namelist.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return b.second < a.second;
        }
        return a.first < b.first;
    });

    cout << namelist[0].first << '\n';

    return 0;
}
