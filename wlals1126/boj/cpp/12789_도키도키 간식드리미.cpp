#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    stack<int> s;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    int start = 1;

    while (!q.empty()) {
        if (q.front() == start) {
            q.pop();
            start++;
        } else if (!s.empty() && s.top() == start) {
            s.pop();
            start++;
        } else {
            s.push(q.front());
            q.pop();
        }
    }

    while (!s.empty()) {
        if (s.top() == start) {
            s.pop();
            start++;
        } else {
            cout << "Sad" << endl;
            return 0;
        }
    }

    cout << "Nice" << endl;
    return 0;
}
