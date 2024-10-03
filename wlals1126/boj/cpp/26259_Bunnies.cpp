#include <iostream>
using namespace std;

long long fibonacci(int x) {
    if (x == 0 || x == 1) return 1;
    
    long long fib[x + 1];
    fib[0] = fib[1] = 1;
    
    for (int i = 2; i <= x; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return fib[x];
}

int main() {
    int n;
    cin >> n; 

    while (n--) {
        int x;
        cin >> x; 
        cout << fibonacci(x) << endl;
    }

    return 0;
}
