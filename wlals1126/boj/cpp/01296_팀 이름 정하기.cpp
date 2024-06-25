#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    cin >> name;

    int N;
    cin >> N;

    int arr[4];
    int max_score = -1;
    string love = "LOVE";
    string ans;

    for (int i = 0; i < N; ++i) {
        string team;
        cin >> team;

        for (int j = 0; j < 4; ++j) {
            char ch = love[j];
            int cnt = count(name.begin(), name.end(), ch) + count(team.begin(), team.end(), ch);
            arr[j] = cnt;
        }

        int sum = 1;
        for (int j = 0; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                sum *= arr[j] + arr[k];
            }
        }

        int score = sum % 100;
        if (max_score == score && !ans.empty()) {
            if (team < ans) {
                ans = team;
            }
        }

        if (max_score < score) {
            max_score = score;
            ans = team;
        }
    }

    cout << ans << "\n";

    return 0;
}
.
