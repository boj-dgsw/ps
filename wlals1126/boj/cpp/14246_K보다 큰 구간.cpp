#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);
    istringstream iss(input);

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        iss >> arr[i];
    }

    long long k;
    cin >> k;

    int left = 0;
    int right = 0;

    long long sum = arr[left];
    long long cnt = 0;

    while (left < n && right < n) {
        if (left > right) {
            right = left;
            sum = arr[left];
        }

        if (sum > k) {
            cnt += n - right;
            sum -= arr[left++];
        } else {
            right++;
            if (right >= n) break;
            sum += arr[right];
        }
    }

    cout << cnt << endl;

    return 0;
}
