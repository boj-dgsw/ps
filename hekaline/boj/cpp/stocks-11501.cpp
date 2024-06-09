#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define OUT

using namespace std;

// 입력
void input(OUT int& n, OUT vector<int>& arr);

// 가장 이득을 크게 보는 값 찾기
long long greedy();

int main()
{
    FAST_IO;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << greedy() << '\n';
    }
}

long long greedy()
{
    long long ans = 0;
    int n; // 날짜 수

    vector<int> arr; // [i]일의 주식 값
    input(n, arr);

    int maxPrice = -1;

    // 뒤에서부터 가장 비싼 값 찾기
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // 주식이 더 비싼 날을 찾았으면
        if (maxPrice < arr[i])
        {
            // 가격이 더 싼 날에 사기 위해 저장
            maxPrice = arr[i];
        }
        else
        {
            // maxPrice보다 싼 값을 찾았으면
            // 정답에 제일 비싼 날 - 현재 주식 가격을 더함
            ans += maxPrice - arr[i];
        }
    }

    return ans;
}

void input(OUT int& n, OUT vector<int>& arr)
{
    cin >> n;
    arr.resize(n);
    for (auto& e : arr)
    {
        cin >> e; // input
    }
}
