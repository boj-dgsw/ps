// greedy
// silver II

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define OUT

using namespace std;

// 입력
void input(OUT int& n, OUT vector<int>& arr, OUT vector<int>& price);

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
    vector<int> price; // [i] = 2라면 주식 가격이 i인 날이 이틀 있음

    input(n, arr, price);

    // 판매 기준 가격
    int p = 10000;

    // 현재 날짜
    int j = 0;

    int stockCnt = 0;
    int stockPrice = 0;

    while (j < n && p >= 0)
    {
        // 입력받은 가격 중 가장 높은 값 찾기
        // while 문을 두 번째로 돌고 있다면 두 번째로 높은 값을 찾는 중
        for (; p >= 0; p--)
        {
            if (price[p])
            {
                price[p] -= 1;
                break;
            }
        }

        // 현재 날짜부터 주식 가격이 가장 높은 날 전까지의 주식 전부 사고
        for (; arr[j] < p; j++)
        {
            stockCnt += 1;
            stockPrice += arr[j];
            price[arr[j]] -= 1;
        }

        j++; // (판매하는 날 건너뛰기)

        // 전부 팔기
        ans += stockCnt * p;

        // 이전에 산 주식 값 빼기
        ans -= stockPrice;

        // reset
        stockCnt = 0;
        stockPrice = 0;
    }

    return ans;
}

void input(OUT int& n, OUT vector<int>& arr, OUT vector<int>& price)
{
    cin >> n;
    arr.resize(n);
    price.resize(10001);
    for (auto& e : arr)
    {
        cin >> e; // input
        price[e] += 1;
    }
}
