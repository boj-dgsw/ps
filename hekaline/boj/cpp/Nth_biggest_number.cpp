#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n*n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
        
        if (pq.size() > n)
        {
            pq.pop();
        }
    }
    
    cout << pq.top();
}
