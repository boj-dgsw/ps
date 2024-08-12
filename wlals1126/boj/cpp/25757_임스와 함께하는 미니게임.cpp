#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n;
    string game;
    cin >> n >> game;

    unordered_map<string, int> games = {
        {"Y", 1},
        {"F", 2},
        {"O", 3}
    };

    unordered_set<string> played;
    int answer = 0;
    int count = 0;
    int nop = games[game];

    for (int i = 0; i < n; i++) {
        string player;
        cin >> player;

        if (played.find(player) != played.end()) {
            continue;
        } else {
            count++;
            played.insert(player);
        }

        if (count == nop) {
            count = 0;
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
