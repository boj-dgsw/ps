#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int N, K;
vector<string> tmp;
vector<string> arr;
vector<bool> visit;
unordered_set<string> res;
string current;

void backtracking(int depth) {
    if (depth == K) {
        res.insert(current);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            current += tmp[i];
            backtracking(depth + 1);
            current.erase(current.size() - tmp[i].size());
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    tmp.resize(N);
    arr.resize(K);
    visit.resize(N, false);

    for (int i = 0; i < N; i++) {
        cin >> tmp[i];
    }

    backtracking(0);

    cout << res.size() << endl;

    return 0;
}
