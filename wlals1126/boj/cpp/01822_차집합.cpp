#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int An, Bn;
    cin >> An >> Bn;
    
    set<int> A;
    
    for (int i = 0; i < An; ++i) {
        int num;
        cin >> num;
        A.insert(num);
    }
    
    for (int i = 0; i < Bn; ++i) {
        int num;
        cin >> num;
        if (A.find(num) != A.end()) {
            A.erase(num);
        }
    }
    
    cout << A.size() << '\n';
    for (int num : A) {
        cout << num << " ";
    }

    return 0;
}
