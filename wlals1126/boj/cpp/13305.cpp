#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> d(n-1);
    vector<long long> prices(n);

    for (long long i = 0; i < n-1; i++) {
        cin >> d[i];
    }

    for (long long i = 0; i < n; i++) {
        cin >> prices[i];
    }

    long long min_price = prices[0]; 
    long long total_cost = 0; 

    for (long long i = 0; i < n - 1; i++) {
        min_price = min(min_price, prices[i]); 
        total_cost += min_price * d[i]; 
    }

    cout << total_cost; 

    return 0;
}
