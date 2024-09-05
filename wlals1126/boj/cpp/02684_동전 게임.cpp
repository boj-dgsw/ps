#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkStrCase(string str, vector<int>& arr) {
    if (str == "TTT") arr[0]++;
    else if (str == "TTH") arr[1]++;
    else if (str == "THT") arr[2]++;
    else if (str == "THH") arr[3]++;
    else if (str == "HTT") arr[4]++;
    else if (str == "HTH") arr[5]++;
    else if (str == "HHT") arr[6]++;
    else if (str == "HHH") arr[7]++;
}

void appendAnswer(const vector<int>& arr) {
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> arr(8, 0);
        string input;
        cin >> input;
        
        for (int lt = 0, rt = 2; rt < input.length(); ++lt, ++rt) {
            string word = input.substr(lt, 3);
            checkStrCase(word, arr);
        }
        
        appendAnswer(arr);
    }
    
    return 0;
}
