#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    getline(cin, input);

    int happy = 0, sad = 0;

    for (size_t i = 0; i < input.length() - 2; ++i) {
        string s = input.substr(i, 3);
        if (s == ":-)") happy++;
        if (s == ":-(") sad++;
    }

    if (happy == 0 && sad == 0) {
        cout << "none" << endl;
    } else if (happy > sad) {
        cout << "happy" << endl;
    } else if (happy < sad) {
        cout << "sad" << endl;
    } else {
        cout << "unsure" << endl;
    }

    return 0;
}
