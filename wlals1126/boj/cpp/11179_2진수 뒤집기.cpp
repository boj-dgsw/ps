#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string binaryString = bitset<32>(n).to_string();
    binaryString = binaryString.substr(binaryString.find('1'));

    reverse(binaryString.begin(), binaryString.end());

    int result = stoi(binaryString, nullptr, 2);

    cout << result << endl;

    return 0;
}
