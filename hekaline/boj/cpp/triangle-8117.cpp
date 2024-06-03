// Silver V
// geometry
// sort
// 삼각형을 이룰 수 있는 세 변 찾기

#include <iostream>
#include <algorithm>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;
    
    vector<int> lengths;
    while (true)
    {
        int temp;
        cin >> temp;
        
        if (temp == 0) break;
        
        lengths.push_back(temp);
    }
    sort(lengths.begin(), lengths.end());
    
    for (int i = 0; i < lengths.size() - 2; i++)
    {
        if (lengths[i + 2] < lengths[i] + lengths[i + 1])
        {
            cout << lengths[i] << ' ' << lengths[i + 1] << ' ' << lengths[i + 2];
            return 0;
        }
    }
    
    cout << "NIE";
}
