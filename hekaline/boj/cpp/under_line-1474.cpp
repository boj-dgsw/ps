// greedy
// string
// Silver I

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int wordNum, targetStrLen;
int wordsLen;
vector<string> words;

string make_sentence();
inline void input();

int main()
{
    FAST_IO
    input();

    cout << make_sentence();
}

string make_sentence()
{
    string sentence;
    int basicLineNum = (targetStrLen - wordsLen) / (wordNum - 1);
    int additionalLineNum = (targetStrLen - wordsLen) % (wordNum - 1);

    for (int i = 0; i < wordNum - 1; i++)
    {
        sentence += words[i] + string(basicLineNum, '_');

        bool bIsForced = additionalLineNum > 0 && (wordNum - i - 1) == additionalLineNum;
        bool bIsRecommended = additionalLineNum > 0 && islower(words[i + 1][0]);
        if (bIsForced || bIsRecommended)
        {
            sentence += '_';
            additionalLineNum--;
        }
    }

    sentence += words.back();
    return sentence;
}

inline void input()
{
    cin >> wordNum >> targetStrLen;
    words.resize(wordNum);

    for (int i = 0; i < wordNum; i++)
    {
        cin >> words[i];
        wordsLen += words[i].length();
    }
}
