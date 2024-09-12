#include <iostream>
#include <string>
using namespace std;

int main() {
    string key, message;
    getline(cin, key);
    getline(cin, message);

    for (char &ch : message) {
        if (isalpha(ch)) {
            bool is_upper = isupper(ch);
            char original_char = is_upper ? ch - 'A' : ch - 'a'; 
            char decrypted_char = key[original_char];
            ch = is_upper ? toupper(decrypted_char) : decrypted_char; 
        }
    }

    cout << message << endl; 
    return 0;
}
