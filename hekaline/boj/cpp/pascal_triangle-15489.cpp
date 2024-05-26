// DP
// 점화식이 공개되어 있음

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

// memo에 파스칼 삼각형을 만드는 함수
void MakePascalTriangle(int size)
{
    // vector<int>의 개수 = size + 1
	memo.resize(size + 1);
	
	for (int i = 1; i <= size; i++)
	{
        // 배열이 계단 모양으로 생성된다.
		memo[i].resize(i + 1);
		
        // 파스칼 삼각형의 양 끝 숫자는 1이다.
		memo[i][1] = memo[i][i] = 1;
		
        // 점화식 (피라미드: 왼쪽 위 + 오른쪽 위) -> (계단: 위 + 오른쪽 위)
		for (int j = 1; j < i; j++)
		{
			memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
		}
	}
}

int main()
{
    // 시작 층, 그 층의 시작 원소 인덱스, 몇 번 내려갈 건지
	int r, c, w;
	cin >> r >> c >> w;
	
    // 파스칼 삼각형 만들기
	MakePascalTriangle(r + w);
    
    // r,c,w를 사용해 이루어진 파스칼 삼각형의 합
	long long ans = 0;
	
    // r 층에서부터 w번 내려감
	for (int i = r; i < r + w; i++)
	{
        // 지나온 층수
		int th = i - r;
        
        // 그 층의 원소를 c + 지나온 층수 개만큼 살펴본다.
		for (int j = c; j <= c + th; j++)
		{
			ans += memo[i][j];
		}
	}
	
	cout << ans;
}
