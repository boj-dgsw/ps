#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int oddCount;
char oddChar;
int alphabets[26];

void solve() {
    string answer = "";
    string reversedAnswer = "";
    string temp;

    if (oddCount == 0) {
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] != 0) {
                int half = alphabets[i] / 2;
                for (int j = 0; j < half; j++) {
                    answer += (char)(i + 'A');
                }
            }
        }
        temp = answer;
        reverse(temp.begin(), temp.end());
        reversedAnswer = temp;
        answer += reversedAnswer;
        cout << answer << endl;
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] != 0) {
                int half = alphabets[i] / 2;
                for (int j = 0; j < half; j++) {
                    answer += (char)(i + 'A');
                }
            }
        }
        temp = answer;
        reverse(temp.begin(), temp.end());
        reversedAnswer = temp;
        answer += oddChar + reversedAnswer;
        cout << answer << endl;
    }
}

int main() {
    string input;
    cin >> input;
    
    for (int i = 0; i < input.length(); i++) {
        int value = input[i] - 'A';
        alphabets[value]++;
    }

    oddCount = 0;
    oddChar = ' ';
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] != 0) {
            if (alphabets[i] % 2 == 1) {
                oddCount++;
                oddChar = (char)(i + 'A');
            }
        }
    }

    if (oddCount >= 2) {
        cout << "I'm Sorry Hansoo" << endl;
    } else {
        solve();
    }

    return 0;
}
