#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr bool JHNAH = true;
constexpr bool JHNAN = false;

// 초록색을 먼저 잘라야 유리
bool getAns(int r, int g, int b);

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    cin.ignore(); // 첫 줄 입력후 입력 버퍼에 남은 개행 문자 제거
    for (int i = 0; i < n; i++)
    {
        // 개행 문자를 기준으로 한 줄 무시
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int r(0), g(0), b(0);
    for (int i = 0; i < m; i++)
    {
        // 띄어쓰기 기준으로 두 정수 무시
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
        cin.ignore(numeric_limits<streamsize>::max(), ' ');

        char col;
        cin >> col;

        switch (col)
        {
            case 'R': r++; break;
            case 'G': g++; break;
            case 'B': b++; break;
            default: break;
        }
    }

    cout << (getAns(r, g, b) == JHNAH ? "jhnah917" : "jhnan917");
}

bool getAns(int r, int g, int b)
{
    if (r == b)
    {
        return g % 2 ? JHNAH : JHNAN;
    }

    return r > b ? JHNAH : JHNAN;
}
