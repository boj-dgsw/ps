// DP
// [SPOILER] ->                            fibonacci numbers

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> vec(n + 1);
    vec[0] = vec[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 15746;
    }
    
    cout << vec[n];
}
