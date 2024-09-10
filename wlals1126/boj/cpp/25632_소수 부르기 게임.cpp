#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    set<int> set1, set2;
    vector<int> primes;

    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) primes.push_back(i);
    }

    for (int prime : primes) {
        if (prime >= n1 && prime <= n2) set1.insert(prime);
    }

    for (int prime : primes) {
        if (prime >= n3 && prime <= n4) set2.insert(prime);
    }

    bool ytTurn = true;
    string result = "";

    while (true) {
        int deleteNum = 0;

        if (ytTurn) {
            if (set1.empty()) {
                result = "yj";
                break;
            }
            ytTurn = false;

            for (int n : set1) {
                if (set2.find(n) != set2.end()) {
                    deleteNum = n;
                    break;
                }
            }

            if (deleteNum == 0) {
                deleteNum = *set1.begin();
            } else {
                set2.erase(deleteNum);
            }
            set1.erase(deleteNum);
        } else {
            if (set2.empty()) {
                result = "yt";
                break;
            }
            ytTurn = true;

            for (int n : set2) {
                if (set1.find(n) != set1.end()) {
                    deleteNum = n;
                    break;
                }
            }

            if (deleteNum == 0) {
                deleteNum = *set2.begin();
            } else {
                set1.erase(deleteNum);
            }
            set2.erase(deleteNum);
        }
    }

    cout << result << endl;

    return 0;
}
t
