#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    bool flag[n];

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            flag[i] = true;
        } else {
            flag[i] = false;
        }
    }

    queue<int> q;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (flag[i]) {
            s.push(num);
        }
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        q.push(num);
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
