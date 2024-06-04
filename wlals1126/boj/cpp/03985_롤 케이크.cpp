#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L, N; 
    cin >> L >> N;
    
    vector<int> cake(L+1, 0); 
    int max = 0; 
    int max_idx = 0;
    int expect = 0; 
    int expect_idx = 0;
    
    for(int i = 1; i <= N; i++) {
        int from, to;
        cin >> from >> to;
        
        if(expect < to - from) { 
            expect = to - from;
            expect_idx = i;
        }
        
        int count = 0;
        for(int j = from; j <= to; j++) {
            if(cake[j] == 0) { 
                cake[j] = i; 
                count++;
            }
        }
        
        if(max < count) { 
            max = count;
            max_idx = i;
        }
    }
    
    cout << expect_idx << endl;
    cout << max_idx << endl;
    
    return 0;
}
