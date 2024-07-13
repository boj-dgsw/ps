#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string jumbleWord(const string &word) {
    int len = word.length();
    if (len <= 3) return word;
    
    string jumbled = word;
    for (int i = 1; i < len - 1; ++i) {
        jumbled[i] = word[len - 1 - i];
    }
    return jumbled;
}

void jumbleSentence(const string &sentence) {
    stringstream ss(sentence);
    string word;
    bool first = true;
    
    while (ss >> word) {
        if (!first) cout << " ";
        cout << jumbleWord(word);
        first = false;
    }
    cout << endl;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;
        jumbleSentence(line);
    }
    return 0;
}
