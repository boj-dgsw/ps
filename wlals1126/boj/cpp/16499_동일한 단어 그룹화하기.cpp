#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<string> uniqueAnagrams;
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        sort(str.begin(), str.end());
        
        uniqueAnagrams.insert(str);
    }
    
    cout << uniqueAnagrams.size() << endl;
    
    return 0;
}
