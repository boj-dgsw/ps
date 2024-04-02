#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int toDecimal(vector<int>& numA, int baseA) {
    int decimal = 0;
    int power = 0;
    for (int i = numA.size() - 1; i >= 0; --i) {
        decimal += numA[i] * pow(baseA, power);
        power++;
    }
    return decimal;
}

void toBaseB(int decimal, int baseB) {
    vector<int> result;
    while (decimal > 0) {
        int remainder = decimal % baseB;
        result.push_back(remainder);
        decimal /= baseB;
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i] << " ";
    }
}

int main() {
    int A, B;
    cin >> A >> B;

    int m;
    cin >> m;

    vector<int> numA(m);
    for (int i = 0; i < m; ++i) {
        cin >> numA[i];
    }

    int decimal = toDecimal(numA, A);
    toBaseB(decimal, B);

    return 0;
}
