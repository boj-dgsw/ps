// Segment Tree
// Platinum V

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n;
vector<long long> tree; // 세그먼트 트리
vector<int> arr;

// 초기 입력 값 (n과 i(1~n)번째 부대의 군인 수
void input();

// input()한 값을 가지고 트리 초기화
long long init(int start, int end, int node);

// 군인 수 업데이트 (idx번 부대의 사람 수를 diff만큼 바꿈)
void update(int left, int right, int idx, int diff, int node);

// idx 번째 군인이 속한 부대 구하기
long long query(int start, int end, int idx, int node);

int main()
{
	FAST_IO;
	
	input();
	init(1, n, 1);
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int cmd; cin >> cmd;
		if (cmd == 1)
		{
			int unit, add;
			cin >> unit >> add;
			
			update(1, n, unit, add, 1);
		}
		else // if cmd == 2
		{
			int soldier; cin >> soldier;
			cout << query(1, n, soldier, 1) << '\n';
		}
	}
}

long long init(int start, int end, int node)
{
  // 리프 노드이므로 arr[start](혹은 arr[end])를 tree[node]에 대입
	if (start == end) return tree[node] = arr[start];

  // 자식 노드가 가지고 있는 인덱스 경계선
  // start가 0이고 end가 10인 루트 노드 -> start가 0이고 end가 5인 왼쪽 자식 + start가 6이고 end가 10인 오른쪽 자식
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int left, int right, int idx, int diff, int node)
{
	if (right < idx || idx < left)
	{
		// out of range
		return;
	}
  
  // 노드가 idx를 포함하고 있다면 차이를 더한다
	tree[node] += diff;

  // 리프 노드이면 리턴
	if (left == right) return;

  // init과 마찬가지로 좌우 자식 인덱스 설정 후 재귀
	int mid = (left + right) / 2;
	update(left, mid, idx, diff, node * 2);
	update(mid + 1, right, idx, diff, node * 2 + 1);
}

long long query(int start, int end, int idx, int node)
{
  // 리프 노드라면 그것이 정답이므로 start(end) 리턴
	if (start == end) return start;

  // init과 마찬가지로 좌우 자식 인덱스 설정 후 재귀, 하지만 둘 중 하나만 한다.
	int mid = (start + end) / 2;

  // 왼쪽 자식이 충분히 크다면 자식의 인덱스 (start ~ mid) 중에 정답이 있음
	if (tree[node * 2] >= idx) return query(start, mid, idx, node * 2);

  // 왼쪽 자식이 충분히 크지 않다면 오른쪽 자식 노드에 정답이 있음, 이때 idx는 왼쪽 자식만큼 빼야 한다.
  // idx가 30인데 왼쪽 16, 오른쪽 20이라면 오른쪽에서 (30 - 16 = 14)번째 사람이 있는 부대를 구해야 하기 때문
	return query(mid + 1, end, idx - tree[node * 2], node * 2 + 1);
}

void input()
{
	cin >> n;
	arr.resize(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	tree.resize(n * 4 + 4);
}
