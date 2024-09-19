#include <iostream>
#include <vector>
using namespace std;

int K;
int swapCount = 0;

void quick_sort(vector<int>& A, int p, int r);
int partition(vector<int>& A, int p, int r);

int main() {
    int N;
    cin >> N >> K;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    quick_sort(A, 0, N - 1);

    if (swapCount < K) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

void quick_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
            swapCount++;
            if (swapCount == K) {
                for (int idx = 0; idx < A.size(); idx++) {
                    cout << A[idx] << " ";
                }
                cout << endl;
                exit(0);
            }
        }
    }

    if (i + 1 != r) {
        swap(A[i + 1], A[r]);
        swapCount++;
        if (swapCount == K) {
            for (int idx = 0; idx < A.size(); idx++) {
                cout << A[idx] << " ";
            }
            cout << endl;
            exit(0); 
        }
    }

    return i + 1;
}
