#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> A(9);
    vector<int> B(9);
    
    for (int i=0; i<9; i++){
        int n;
        cin >> n;
        A[i] = n;
        B[i] = 1;
    }
    B[7] = 0;
    B[8] = 0;
    
    sort(A.begin(), A.end());
    
    do {
        int sum = 0;
        for (int i = 0; i < 9; ++i){
            if (B[i] != 0){
                sum += A[i];
            }
        }
        if (sum == 100){
            for (int i = 0; i < 9; ++i){
                if (B[i] != 0){
                    cout << A[i] << "\n";
                }
            }
            break;
        }
    } while (next_permutation(A.begin(), A.end()));
    
    return 0;
}
