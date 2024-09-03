// divide and conquer

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input();
void swap(int idx1, int idx2) noexcept;
int partition(vector<int>& arr, int left, int right);
void divide_and_conquer(vector<int>& arr, int left, int right);

// alias of divide_and_conquer
void quick_sort(vector<int>& arr, const int left, const int right)
{
    divide_and_conquer(arr, left, right);
}

vector<int> arr;
vector<int> arrcmp;
int n;
int sameCnt;

int main()
{
    FAST_IO;
    input();
    quick_sort(arr, 0, n - 1);

    // 비교하면서 arr이 arrcmp와 같은 경우가 있으면
    // swap에서 자동 처리함.
    cout << 0;
}

void input()
{
    cin >> n;

    arr.resize(n);
    arrcmp.resize(n);

    for (int &element : arr)
    {
        cin >> element;
    }

    for (int &element : arrcmp)
    {
        cin >> element;
    }

    for (int i = 0; i < n; i++)
    {
        sameCnt += arr[i] == arrcmp[i];
    }

    // 초기에 같음
    if (arr == arrcmp)
    {
        cout << 1;
        exit(0);
    }
}

// 분할 정복 (문제의 quick_sort 함수와 같음)
void divide_and_conquer(vector<int>& arr, const int left, const int right)
{
    // 스택으로 재귀 대체
    stack<pair<int, int>> _stack;
    _stack.emplace(left, right);

    if (left >= right)
    {
        return;
    }

    while (!_stack.empty())
    {
        int low = _stack.top().first;
        int high = _stack.top().second;
        _stack.pop();

        // 정렬된 피벗
        int pivot = partition(arr, low, high);

        if (low < pivot - 1)
        {
            _stack.emplace(low, pivot - 1);
        }

        if (pivot + 1 < high)
        {
            _stack.emplace(pivot + 1, high);
        }
    }
}

// 피벗 왼쪽에 작은 수, 오른쪽에 큰 수를 두며 정렬.
// 피벗 위치를 반환
int partition(vector<int>& arr, const int left, const int right)
{
    int pivot = arr[right];

    // 정렬할 부분의 시작점 -1 (전위증가연산자를 사용하며 정상적으로 동작함)
    int i = left - 1;

    // 시작점부터 끝점 - 1까지 돌면서 피벗보다 작으면
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(++i, j);
        }
    }

    // arr[j]가 모두 피벗보다 작았으면 넘어감
    // (피벗 본인이 이미 정렬 후 위치해야 할 곳에 있으면 넘어감)
    if (i + 1 != right)
    {
        swap(i + 1, right);
    }

    return i + 1;
}

// std::swap를 가림
// 두 배열이 같은지 확인하기 위함
void swap(const int idx1, const int idx2) noexcept
{
    sameCnt -= (arr[idx1] == arrcmp[idx1]) + (arr[idx2] == arrcmp[idx2]);
    std::swap(arr[idx1], arr[idx2]);
    sameCnt += (arr[idx1] == arrcmp[idx1]) + (arr[idx2] == arrcmp[idx2]);

    if (sameCnt == n)
    {
        cout << 1;
        exit(0);
    }
}
