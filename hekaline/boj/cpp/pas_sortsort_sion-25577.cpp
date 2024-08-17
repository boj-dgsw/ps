// Gold IV
// Permutation Cycle Decomposition
// Greedy
// Sort

#include <iostream>
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int n;
vector<int> arr;

int getAnswer();
void input()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    FASTIO
    input();
    cout << getAnswer();
}

[[nodiscard]]
int getAnswer()
{
    // arr 정렬한 배열
    vector<int> arrTemp = arr;
    sort(arrTemp.begin(), arrTemp.end());

    // 좌표 압축
    // 1 300 2 9012 3 400 0 (arr)
    // 0 1 2 3 300 400 9012 (arrTemp)
    // 1 4 2 6 3 5 0 ((compressed) arr)

    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(arrTemp.begin(), arrTemp.end(), arr[i]) - arrTemp.begin();
        // cout << arr[i] << ' ';
    }

    int cycleCnt = 0;
    vector visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        cycleCnt--;
        int next = arr[i];
        while (!visited[next])
        {
            visited[next] = true;
            next = arr[next];
            cycleCnt++;
        }
    }

    return cycleCnt;
}
