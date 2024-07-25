#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int result = 0;

    for (int i = 0; i < 3; ++i) {
        string input;
        getline(cin, input);

        if (input == "Fizz" || input == "Buzz" || input == "FizzBuzz") {
            continue;
        } else {
            result = stoi(input) + (3 - i);
        }
    }

    if (result % 3 == 0 && result % 5 == 0) {
        cout << "FizzBuzz" << endl;
    } else if (result % 3 == 0) {
        cout << "Fizz" << endl;
    } else if (result % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
