#include <iostream>
#include <vector>
#define OUT
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input(OUT int& n, OUT vector<int>& allCards, OUT vector<bool>& isCardExistsArray);
void output(const vector<int>& allCards, const vector<int>& answers);
vector<int> getAnswers(const vector<int>& allCards, const vector<bool>& isCardExistsArray);

int main()
{
	FAST_IO
	
	int n;
	vector<int> allCards;
	vector<bool> isCardExistsArray;
	
	input(OUT n, OUT allCards, OUT isCardExistsArray);
	vector<int> answers = getAnswers(allCards, isCardExistsArray);
	
	output(allCards, answers);
}

vector<int> getAnswers(const vector<int>& allCards, const vector<bool>& isCardExistsArray)
{
	// Eratosthenes
	
	int cardSize = allCards.size();
	vector<int> answer;
	answer.resize(isCardExistsArray.size());
	
	for (int i = 0; i < cardSize; i++)
	{
		int currentCard = allCards[i];
		for (int j = currentCard * 2; j <= 1'000'000; j += currentCard)
		{
			if (isCardExistsArray[j])
			{
				answer[currentCard] += 1;
				answer[j] -= 1;
			}
		}
	}
	
	return answer;
}

void input(OUT int& n, OUT vector<int>& allCards, OUT vector<bool>& isCardExistsArray)
{
	cin >> n;
	
	isCardExistsArray.resize(1'000'001);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		
		allCards.push_back(temp);
		isCardExistsArray[temp] = true;
	}
}

void output(const vector<int>& allCards, const vector<int>& answers)
{
	int n = allCards.size();
	for (int i = 0; i < n; i++)
	{
		cout << answers[allCards[i]] << ' ';
	}
}
