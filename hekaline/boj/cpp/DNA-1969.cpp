// Greedy
// Silver IV
// 주어진 DNA 배열? 과 가장 비슷한 DNA를 찾고
// 그 DNA와 차이 나는 문자(char) 개수를 구한다.

#include <iostream>
#include <vector>

using namespace std;

// 우선순위 (ABC 순)
constexpr int T = 3;
constexpr int A = 0;
constexpr int G = 2;
constexpr int C = 1;

char intToNucleotide(int n)
{
    switch (n)
    {
        case T : return 'T';
        case A : return 'A';
        case G : return 'G';
        case C : return 'C';
        default : return 'X';
    }
}

int nucleotideToInt(char nucleotide)
{
    switch (nucleotide)
    {
        case 'T' : return T;
        case 'A' : return A;
        case 'G' : return G;
        case 'C' : return C;
        default : return -1;
    }
}

void input();
pair<string, int> getAnswer();

int n, m;
vector<string> strArr;

int main()
{
    input();
    auto ans = getAnswer();

    cout << ans.first << '\n' << ans.second;
}

pair<string, int> getAnswer()
{
    string ansStr = "";
    int ansInt = 0;

    int* arr = new int[4] {0, 0, 0, 0};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[nucleotideToInt(strArr[j][i])] += 1;
        }

        int maxCnt = 0;
        char maxChar = 'X';
        for (int j = 0; j < 4; j++)
        {
            if (maxCnt < arr[j])
            {
                maxCnt = arr[j];
                maxChar = intToNucleotide(j);
            }
        }

        ansStr += maxChar;
        ansInt += n - maxCnt;
        arr = new int[4]{0, 0, 0, 0};
    }

    return {ansStr, ansInt};
}

void input()
{
    cin >> n >> m;
    strArr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> strArr[i];
    }
}
