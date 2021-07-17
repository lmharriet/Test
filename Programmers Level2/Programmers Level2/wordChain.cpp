#include <iostream>
#include <vector>
#include <String>
#include <unordered_map>

using namespace std;

//21.07.18

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	unordered_map<string, int> umWordChain;
	
	for (int i = 0; i < words.size(); i++)
	{
		if (i + 1 == words.size())
		{
			if (umWordChain.count(words[i]) == 1)
			{
				answer = { ((i + 1) % n) + 1 ,((i + 1) / n) + 1 };
			}
			else
			{
				answer = { 0,0 };
			}
			break;
		}

		if (umWordChain.count(words[i + 1]) == 1)
		{
			answer = { ((i + 1) % n) + 1 ,((i + 1) / n) + 1 };
			break;
		}

		if (words[i][words[i].size() - 1] != words[i + 1][0])
		{
			answer = { ((i + 1) % n) + 1 ,((i + 1) / n) + 1 };
			break;
		}
		else
		{
			umWordChain[words[i]] = i / n;
		}

	}

	return answer;
}

int main()
{

	solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot","tank" });
	cout << '\n';
	solution(5, { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" });
	cout << '\n';
	solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });

	return 0;
}