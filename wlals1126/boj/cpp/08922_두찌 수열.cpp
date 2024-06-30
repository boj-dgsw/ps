#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<int> next(const vector<int>& tuple) {
    int n = tuple.size();
    vector<int> nextTuple(n);
    for (int i = 0; i < n; ++i) {
        nextTuple[i] = abs(tuple[i] - tuple[(i + 1) % n]);
    }
    return nextTuple;
}

bool isZero(const vector<int>& tuple) {
    for (int num : tuple) {
        if (num != 0) return false;
    }
    return true;
}

void process(int n, const vector<int>& initialTuple) {
    set<vector<int>> seenTuples;
    vector<int> currentTuple = initialTuple;
    
    for (int step = 0; step <= 1000; ++step) {
        if (isZero(currentTuple)) {
            cout << "ZERO" << endl;
            return;
        }
        if (seenTuples.count(currentTuple)) {
            cout << "LOOP" << endl;
            return;
        }
        seenTuples.insert(currentTuple);
        currentTuple = next(currentTuple);
    }
    
    cout << "LOOP" << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> initialTuple(n);
        for (int i = 0; i < n; ++i) {
            cin >> initialTuple[i];
        }
        
        process(n, initialTuple);
    }
    
    return 0;
}
E
