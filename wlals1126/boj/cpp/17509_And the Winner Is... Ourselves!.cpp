#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> problems(11);
    for (int i = 0; i < 11; i++) {
        cin >> problems[i].first >> problems[i].second;
    }

    sort(problems.begin(), problems.end());

    int totalTime = 0;
    int totalPenalty = 0;

    for (int i = 0; i < 11; i++) {
        totalTime += problems[i].first;
        totalPenalty += totalTime + 20 * problems[i].second;
    }

    cout << totalPenalty << endl;

    return 0;
}
