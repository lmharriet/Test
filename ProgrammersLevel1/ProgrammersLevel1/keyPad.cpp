#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Programmers Level_1 2020카카오인턴쉽
	키패드 누르기

	1 2 3
	4 5 6
	7 8 9
	* 0 #
   (L) (R)  //시작 위치

   1 4 7 = L
   3 6 9 = R
   2 5 8 0  = 가장 가까이 위치한 손가락
  */
struct Pos
{
	uint8_t x;
	uint8_t y;
public:
	Pos() {};
	Pos(uint8_t a, uint8_t b) :x(a), y(b) {};
};

uint8_t GetDistance(Pos A, Pos B)
{
	return 	abs(A.x - B.x) + abs(A.y - B.y);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	//[0,0]~ [3,2] 좌표로 움직여진 손가락 위치 
	Pos LeftPinger(3, 0);
	Pos RightPinger(3, 2);
	Pos KeyPadPos;	 //검사 할 KeyPad 숫자 위치

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0)	// 0
		{
			KeyPadPos.x = 3;
			KeyPadPos.y = 1;
		}
		else
		{
			if (numbers[i] % 3 == 0)	// 3,6,9
			{
				answer += "R";
				RightPinger.x = (numbers[i] / 3) - 1;
				RightPinger.y = 2;
				continue;
			}

			if (numbers[i] % 3 == 1)	// 1,4,7
			{
				answer += "L";
				LeftPinger.x = numbers[i] / 3;
				LeftPinger.y = 0;
				continue;
			}

			//2 5 8
			KeyPadPos.x = numbers[i] / 3;
			KeyPadPos.y = 1;
		}
		
		if (GetDistance(KeyPadPos, LeftPinger) > GetDistance(KeyPadPos, RightPinger))
		{
			RightPinger.x = KeyPadPos.x;
			RightPinger.y = KeyPadPos.y;
			answer += "R";
		}
		else if (GetDistance(KeyPadPos, LeftPinger) < GetDistance(KeyPadPos, RightPinger))
		{
			LeftPinger.x = KeyPadPos.x;
			LeftPinger.y = KeyPadPos.y;
			answer += "L";
		}
		else
		{
			answer += toupper(hand[0]); //소문자 l or r을 대문자L or R로 치환 후 저장
			if (toupper(hand[0]) == 'L')
			{
				//왼손잡이면 왼손이 키패드에 위치하도록 변경
				LeftPinger.x = KeyPadPos.x;
				LeftPinger.y = KeyPadPos.y;
			}
			else
			{
				//오른손잡이면 오른손이 키패드에 위치하도록 변경
				RightPinger.x = KeyPadPos.x;
				RightPinger.y = KeyPadPos.y;
			}
		}
	}
	return answer;
}

void GetAnswer(string InMySolution, string InAnswer)
{
	int count = 0;
	for (int i = 0; i < InAnswer.size(); i++)
	{
		if (InMySolution[i] == InAnswer[i])
		{
			count++;
		}
	}
	if (count == InAnswer.size())
	{
		cout << "정답" << '\n';
	}
	else
	{
		cout << "오답" << '\n';
	}
}
int main(void)
{
	//cout << sizeof(Pos);
	string MySolution = "";
	string Answer = "";

	GetAnswer(solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right"), "LRLLLRLLRRL");
	GetAnswer(solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left"), "LRLLRRLLLRR");
	GetAnswer(solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right"), "LLRLLRLLRL");


	return 0;
}