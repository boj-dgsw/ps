
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    int piece = 0;

    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            board[i][j] = s[j];
            if ((i + j) % 2 == 0 && board[i][j] == 'F') {
                piece++;
            }
        }
    }

    cout << piece << endl;
    
    return 0;
}
