#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;


#pragma region weekly challenge_1 (부족한 금액 계산하기)
//
//long long solution(int price, int money, int count)
//{
//	long long answer = -1, multiple = 0;
//
//	for (long long i = 1; i <= count; i++)
//	{
//		multiple += (price * i);
//	}
//
//	answer = (money - multiple < 0) ? (money - multiple) * -1 : 0;
//	return answer;
//}

#pragma endregion

#pragma region weekly challenge_2(상호 평가)
//
//char GetGrade(float InScore)
//{
//	if (InScore >= 90) return 'A';
//	if (InScore >= 80) return 'B';
//	if (InScore >= 70) return 'C';
//	if (InScore >= 50) return 'D';
//
//	return 'F';
//}
//string solution(vector<vector<int>> scores) {
//	string answer = "";
//	unordered_map<int, int> myself;
//	vector<int> row;
//	int sameScoreCount = 0;
//	float Avg = 0;
//	bool isMinMax = false;
//
//	for (int i = 0; i < scores.size(); i++)
//	{
//		myself[i] = scores[i][i];
//
//		for (int j = 0; j < scores[i].size(); j++)
//		{
//			row.emplace_back(scores[j][i]);
//			Avg += scores[j][i];
//
//			if (myself[i] == scores[j][i]) //내가 유일하게 나한테 최고점 혹은 최저점을 준 게 아닐 수 있으니 같은 점수 체크
//			{
//				sameScoreCount++;
//			}
//		}
//
//		sort(row.begin(), row.end());
//
//
//		if (myself[i] == row[0] || myself[i] == row[row.size() - 1])
//		{
//			if (isMinMax == false && sameScoreCount <= 1)
//			{
//				Avg -= myself[i];
//				isMinMax = true;
//			}
//		}
//
//		answer += GetGrade(Avg / (scores.size() - static_cast<int>(isMinMax)));
//
//		//데이터 초기화
//		row.clear();
//		Avg = 0;
//		sameScoreCount = 0;
//		isMinMax = false;
//	}
//
//	return answer;
//}
//
#pragma endregion

#pragma region weekly Challenge 퍼즐 조각 채우기 (X)
//
//int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
//	int answer = -1;
//
//	/*int count = 0;
//	for (int i = 0; i < game_board.size(); i++)
//	{
//		for (int j = 0; j < game_board[i].size(); j++)
//		{
//			if (game_board[i][j] == 1)
//			{
//				game_board[i][j] = 2;
//				count++;
//				continue;
//			}
//
//			if(i + 1< game_board.size())
//			{
//				if (game_board[i + 1][j] == 1)
//				{
//
//				}
//			}				
//
//		}
//
//	}*/
//
//
//	return answer;
//}

#pragma endregion

#pragma region weely Challenge_4 (직업군 추천하기)


string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	string answer = "";

	unordered_map<string, int> pref_Languages;
	for (int i = 0; i < languages.size(); i++)
		pref_Languages[languages[i]] = preference[i];
	
	int categoryScore = -1; // 직업군 선호도 점수
	int findCount = 0;		// 각 string 에서 선호하는 언어를 찾아낸 횟수
	string Category = "";	// 가장 먼저 나오는 string은 카테고리가 됨 ex) SI, CONTENTS 
	unordered_map<string, int> category_Score;
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].length(); j++)
		{
			if (categoryScore == -1 && table[i][j] == ' ')
			{
				// 카테고리 분류하는 곳
				Category = move(answer);
				category_Score[Category] = 0;
				categoryScore = 5;	

				continue;
			}

			if (table[i][j] == ' ')
			{
				//공백까지 찾았으면 검사 ( JAVA, JAVASCRIPT 처럼 같은 단어가 무조건 들어있는 경우 때문에 공백까지 체크)
				if (pref_Languages.count(answer) > 0)
				{
					category_Score[Category] += (pref_Languages[answer] * categoryScore);
					answer = "";
					categoryScore--;
					findCount++;

					if (findCount == pref_Languages.size())break;
				}
				else
				{
					answer = "";
					categoryScore--;
				}
				continue;
			}

			answer += table[i][j];

			if (j == table[i].length() - 1) // 마지막이면 공백 없으므로 여기서 검사
			{
				if (pref_Languages.count(answer) > 0)
				{
					category_Score[Category] += (pref_Languages[answer] * categoryScore);
				}
				answer = "";
			}

		}//end of j

		Category = "";
		answer = "";
		categoryScore = -1;
	}


	unordered_map<string, int>::iterator job = max_element(category_Score.begin(), category_Score.end(),
		[](const std::pair<string, int>& a, const std::pair<string, int>& b)
		{
			if (a.second == b.second)
				return  a.first > b.first;
			return a.second < b.second;
		});

	answer = job->first; 

	return answer;
}

#pragma endregion



int main()
{
	//weekly challenge_1(부족한 금액 계산하기)
	//cout << solution(3, 20, 4);

	//weekly challenge_2(상호 평가)
	//cout << solution({ { 100,90,98,88,65 }, { 50,45,99,85,77 }, { 47,88,95,80,67 }, { 61,57,100,80,65 }, { 24,90,94,75,65 } });
	//cout << solution({{ 50,90 }, { 50,87 }});
	//cout << solution({ {70,49,90 }, { 68,50,38 },{73,31,100} });

	//weekly challenge_3(퍼즐 조각 채우기) //not yet
	//cout << solution({ {1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0} },
	//	{ {1,0,0,1,1,0},{1,0,1,0,1,0}, {0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0}, {0,1,0,0,0,0} });

	/*cout << solution({
		"SI JAVA JAVASCRIPT SQL PYTHON C#",
		"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
		"HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
		"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
		"GAME C++ C# JAVASCRIPT C JAVA" },
		{ "PYTHON", "C++", "SQL" },
		{ 7,5,5 });*/

	cout << solution({
	"SI JAVA JAVASCRIPT SQL PYTHON C#",
	"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
	"HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
	"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
	"GAME C++ C# JAVASCRIPT C JAVA" },
		{ "JAVA", "JAVASCRIPT" },
		{ 7,5 });

	return 0;
}