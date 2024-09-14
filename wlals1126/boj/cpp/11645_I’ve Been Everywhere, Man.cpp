#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n; 
        cin >> n;
        
        set<string> cities; 
        
        for (int i = 0; i < n; ++i) {
            string city;
            cin >> city;
            cities.insert(city);
        }
        
        cout << cities.size() << endl;
    }

    return 0;
}
