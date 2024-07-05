#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void encrypt(const string &msg) {
    int L = msg.size();
    int K = ceil(sqrt(L));
    int M = K * K;
    string padded = msg + string(M - L, '*');
    
    vector<vector<char>> table(K, vector<char>(K));
    for (int i = 0; i < M; ++i) {
        table[i / K][i % K] = padded[i];
    }
    
    vector<vector<char>> rotated(K, vector<char>(K));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            rotated[j][K - 1 - i] = table[i][j];
        }
    }
    
    string encrypted;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            if (rotated[i][j] != '*') {
                encrypted += rotated[i][j];
            }
        }
    }
    
    cout << encrypted << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        string msg;
        getline(cin, msg);
        encrypt(msg);
    }
    
    return 0;
}
