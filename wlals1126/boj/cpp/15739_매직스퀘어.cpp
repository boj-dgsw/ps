#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isMagicSquare(const vector<vector<int>>& matrix, int n) {
    int targetSum = n * (n * n + 1) / 2;
    
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        if (rowSum != targetSum) {
            return false;
        }
    }
    
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += matrix[i][j];
        }
        if (colSum != targetSum) {
            return false;
        }
    }
    
    int sum1 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += matrix[i][i];
    }
    if (sum1 != targetSum) {
        return false;
    }
    
    int sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum2 += matrix[i][n - 1 - i];
    }
    if (sum2 != targetSum) {
        return false;
    }
    
    unordered_set<int> elements;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 1 || matrix[i][j] > n * n) {
                return false;
            }
            elements.insert(matrix[i][j]);
        }
    }
    if (elements.size() != n * n) {
        return false;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    if (isMagicSquare(matrix, n)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    
    return 0;
}
