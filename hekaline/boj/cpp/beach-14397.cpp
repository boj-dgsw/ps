// implementation
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr char WATER = '.';
constexpr char LAND = '#';

int n, m;
vector<vector<char>> arr;

void input();
int get_beach_length();

bool is_index_valid(int i, int j)
{ return 0 <= i && i < n && 0 <= j && j < m; }

bool is_water(int i, int j)
{ return is_index_valid(i, j) && arr[i][j] == WATER; }

int main()
{
    FAST_IO
    input();

    cout << get_beach_length();
}

int get_beach_length()
{
    int res = 0;

    // i % 2 == 0 ? up - 1 : up + 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 해변 길이를 재는 것은 땅 혹은 물 하나만 골라서 해야 함
            if (arr[i][j] != LAND) continue;

            // 만약 [i][j]가 땅이라면

            // 좌우는 i와 관계 없이 공통으로 살펴보기
            res += is_water(i, j - 1);
            res += is_water(i, j + 1);

            // 짝수 번째 줄 (0부터 시작), [i +- 1][j], [i +- 1][j - 1] 살펴보기
            if (i % 2 == 0)
            {
                res += is_water(i - 1, j - 1);
                res += is_water(i - 1, j);

                res += is_water(i + 1, j - 1);
                res += is_water(i + 1, j);
            }
            // 홀수 번째 줄, [i +- 1][j - 1], [i +- 1][j + 1] 살펴보기
            else
            {
                res += is_water(i - 1, j);
                res += is_water(i - 1, j + 1);

                res += is_water(i + 1, j);
                res += is_water(i + 1, j + 1);
            }
        } // end of for(j)
    } // end of for(i)

    return res;
}


void input()
{
    cin >> n >> m;
    arr = vector(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}
