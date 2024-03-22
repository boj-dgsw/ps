#include <iostream>
#include <algorithm>
using namespace std;

int* arr1;
int* arr2;
int n;

void input()
{
    cin >> n;
    arr1 = new int[n];
    arr2 = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    input();
    
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n, greater<int>());
    
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    
    cout << sum;
}
