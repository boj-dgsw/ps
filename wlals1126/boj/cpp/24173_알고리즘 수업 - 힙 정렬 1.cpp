#include <iostream>
#include <vector>
using namespace std;

int N, K, swapCount = 0;
vector<int> A;

void heapify(int k, int n) {
    int left = 2 * k, right = 2 * k + 1, smallest = k;

    if (left <= n && A[left] < A[smallest])
        smallest = left;
    if (right <= n && A[right] < A[smallest])
        smallest = right;

    if (smallest != k) {
        swap(A[k], A[smallest]);
        swapCount++;
        if (swapCount == K) {
            cout << min(A[k], A[smallest]) << " " << max(A[k], A[smallest]) << endl;
            exit(0);
        }
        heapify(smallest, n);
    }
}

void build_min_heap(int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify(i, n);
}

void heap_sort(int n) {
    build_min_heap(n);
    for (int i = n; i > 1; i--) {
        swap(A[1], A[i]);
        swapCount++;
        if (swapCount == K) {
            cout << min(A[1], A[i]) << " " << max(A[1], A[i]) << endl;
            exit(0);
        }
        heapify(1, i - 1);
    }
}

int main() {
    cin >> N >> K;
    A.resize(N + 1); 
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    heap_sort(N);

    cout << -1 << endl;
    return 0;
}
