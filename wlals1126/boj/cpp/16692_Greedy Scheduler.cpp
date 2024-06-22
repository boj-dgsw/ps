#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    vector<int> t(c);
    for (int i = 0; i < c; ++i) {
        cin >> t[i];
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 1; i <= n; ++i) {
        pq.push({0, i});
    }
    
    vector<int> result(c);
    for (int i = 0; i < c; ++i) {
        auto [free_time, cashier_id] = pq.top();
        pq.pop();
        result[i] = cashier_id;

        pq.push({free_time + t[i], cashier_id});
    }
    
    for (int i = 0; i < c; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
