#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> deque;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num == 1) {
            int x;
            cin >> x;
            deque.push_front(x);
        } else if (num == 2) {
            int x;
            cin >> x;
            deque.push_back(x);
        } else if (num == 3) {
            if (!deque.empty()) {
                cout << deque.front() << "\n";
                deque.pop_front();
            } else {
                cout << -1 << "\n";
            }
        } else if (num == 4) {
            if (!deque.empty()) {
                cout << deque.back() << "\n";
                deque.pop_back();
            } else {
                cout << -1 << "\n";
            }
        } else if (num == 5) {
            cout << deque.size() << "\n";
        } else if (num == 6) {
            cout << (deque.empty() ? 1 : 0) << "\n";
        } else if (num == 7) {
            if (!deque.empty()) {
                cout << deque.front() << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if (num == 8) {
            if (!deque.empty()) {
                cout << deque.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
