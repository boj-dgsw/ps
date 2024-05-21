#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr_length;
    cin >> arr_length;

    vector<long long> arr(arr_length);

    for (int i = 0; i < arr_length; i++) {
        cin >> arr[i];
    }

    long long odd = 0;
    long long even = 0;

    long long odd_cnt = 0;
    long long even_cnt = 0;

    for (int i = 0; i < arr_length; i++) {
         if (arr[i] % 2 == 0) {
            even_cnt++;
            odd += odd_cnt;
        } else {
            odd_cnt++;
            even += even_cnt;
        }
    }

    cout << min(even, odd) << endl;
    
    return 0;
}
