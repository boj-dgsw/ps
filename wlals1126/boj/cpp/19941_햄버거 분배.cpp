#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string inputString;
    cin >> inputString;

    vector<bool> ate(n, false);
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (inputString[i] == 'P') {
            for (int j = i - k; j <= i + k; j++) {
                if (j >= 0 && j < n && inputString[j] == 'H' && !ate[j]) {
                    ate[j] = true;
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
