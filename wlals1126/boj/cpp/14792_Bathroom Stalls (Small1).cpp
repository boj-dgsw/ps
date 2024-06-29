#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int length, start, end;
    bool operator<(const Interval& other) const {
        if (length == other.length) {
            return start > other.start;
        }
        return length < other.length;
    }
};

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;
        
        priority_queue<Interval> pq;
        pq.push({N, 1, N});
        
        int last_min_LR, last_max_LR;
        
        for (int i = 0; i < K; ++i) {
            Interval current = pq.top();
            pq.pop();
            
            int mid = (current.start + current.end) / 2;
            int left_len = mid - current.start;
            int right_len = current.end - mid;
            
            last_min_LR = min(left_len, right_len);
            last_max_LR = max(left_len, right_len);
            
            if (left_len > 0) pq.push({left_len, current.start, mid - 1});
            if (right_len > 0) pq.push({right_len, mid + 1, current.end});
        }
        
        cout << "Case #" << t << ": " << last_max_LR << " " << last_min_LR << "\n";
    }
    
    return 0;
}
