#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    int size = (str.length() * 5) - (str.length() - 1);
    int arr1[] = { -2, -1, -1, 0, 0, 1, 1, 2 };
    int arr2[] = { 0, -1, 1, -2, 2, -1, 1, 0 };
    string arr[5][size];
    int strIndex = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = ".";
        }
    }

    for (int i = 2; i < size; i += 4) {
        arr[2][i] = str.substr(strIndex, 1);
        strIndex++;
        for (int j = 0; j < 8; j++) {
            int y = 2 + arr1[j];
            int x = i + arr2[j];
            arr[y][x] = "#"; 
        }
    }

     for (int i = 10; i < size; i += 12) {
        for (int j = 0; j < 8; j++) {
            int y = 2 + arr1[j];
            int x = i + arr2[j];
            arr[y][x] = "*";
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}피터팬 프레임
