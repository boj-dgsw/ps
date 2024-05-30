// Geometry
// Silver V

#include <iostream>
#include <algorithm>

// 빠른 입출력
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using ld = long double;

ld get_smallest_angle(ld h, ld m, ld s);

int main()
{
	FAST_IO;
	
	int t;
	cin >> t;
	cout.precision(10);
	
	while (t--)
	{
		// 시, 분, 초 입력
		int h, m, s;
		cin >> h >> m >> s;
		
		cout << get_smallest_angle(h, m, s) << '\n';
	}
}

[[nodiscard]]
ld get_smallest_angle(ld h, ld m, ld s)
{
	// 12시를 원점으로 초침, 분침, 시침의 각
	ld a1 = 6 * s;
	ld a2 = 6 * m + 6 * (s / 60.0);
	ld a3 = 30 * h + 30 * (m / 60.0) + 30 * (s / 3600.0);
	// cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
	
	ld arr[] = { a1, a2, a3 };
	sort(arr, arr + 3);

	// 정렬한 침들 사이의 각(angle) 3개
	ld oa = arr[1] - arr[0];
	ld ob = arr[2] - arr[1];
	ld oc = 360.0 - arr[2] + arr[0];

	// 각 크기 정렬
	ld oArr[] = { oa, ob, oc };
	sort(oArr, oArr + 3);

	// 가장 작은 값 반환
	return oArr[0];
}
