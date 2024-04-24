#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, K;
    cin >> A >> K;
    vector<int> array(A);
    for (int i = 0; i < A; ++i) {
        cin >> array[i];
    }
    
    int cnt = 0;

    for (int i = array.size() - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (array[j] > array[j+1]) {
                cnt++;
                swap(array[j], array[j+1]);
                if (cnt == K) {
                    cout << array[j] << " " << array[j+1] << endl;
                    return 0;
                }
            }
        }
    }

    if (cnt < K) {
        cout << -1 << endl;
    }

    return 0;
}