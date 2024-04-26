#include <iostream>
#include <string>

using namespace std;

int main() {
    string originalNum1, originalNum2;
    cin >> originalNum1 >> originalNum2;

    string maxNum1 = originalNum1, maxNum2 = originalNum2;
    string minNum1 = originalNum1, minNum2 = originalNum2;

    for (char &c : maxNum1)
        if (c == '5') c = '6';
    for (char &c : maxNum2)
        if (c == '5') c = '6';
    int maxSum = stoi(maxNum1) + stoi(maxNum2);

    for (char &c : minNum1)
        if (c == '6') c = '5';
    for (char &c : minNum2)
        if (c == '6') c = '5';
    int minSum = stoi(minNum1) + stoi(minNum2);

    cout << minSum << " " << maxSum;

    return 0;
}
