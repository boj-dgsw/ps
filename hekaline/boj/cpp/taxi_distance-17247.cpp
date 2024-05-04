// Geometry (기하학)
// 맨해튼 거리

#include <iostream>
using namespace std;

struct coord 
{ 
    int i; int j;
    coord(int _i, int _j) : i(_i), j(_j) {}
};

int main()
{
    coord a(-1, -1);
    coord b(-1, -1);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            int temp; cin >> temp;
            if (temp) 
            {
                if (a.i == -1)
                {
                    a.i = i;
                    a.j = j;
                } else
                {
                    b.i = i;
                    b.j = j;
                }
            }
        }
    }
    
    cout << abs(a.i - b.i) + abs(a.j - b.j);
}
