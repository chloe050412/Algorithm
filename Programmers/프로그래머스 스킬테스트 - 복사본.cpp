//#include <iostream>
//#include <string>
//
//using namespace std;
//int solution(int n)
//{
//	std::string num = std::to_string(n);
//	int result = 0;
//
//	for (auto& one : num)
//	{
//		result += one - '0';
//	}
//
//	return result;
//}


//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) 
//{
//	vector<int> answer;
//	
//	if (arr.size() == 1)
//	{
//		answer.push_back(-1);
//		return answer;
//	}
//
//	arr.erase(std::min_element(arr.begin(), arr.end()));
//
//	for (auto num : arr)
//	{
//		answer.push_back(num);
//	}
//
//	return answer;
//}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(string expression) 
//{
//	bool plus, minus, mul = false;
//	long long answer = 0;
//
//	for (auto one : expression)
//	{
//		if (one == '+')
//			plus = true;
//		if (one == '-')
//			minus = true;
//		if (one == '*')
//			mul = true;
//	}
//
//	
//	int number = 0;
//	for (auto one : expression)
//	{
//		if(one != '+')
//	}
//
//	return answer;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//int isPrimeE(int num, int index)
//{
//	std::vector<int> none;
//	int count = 0;
//
//	for (int i = 2; i <= num; ++i)
//	{
//		if (std::find(none.begin(), none.end(), i) != none.end())
//			continue;
//
//		for (int j = i; j <= num; ++j)
//		{
//			if (std::find(none.begin(), none.end(), j) != none.end())
//				continue;
//
//			if (j % i == 0)
//			{
//				none.push_back(j);
//				++count;
//
//				if (count == index)
//					return j;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int num, index = 0;
//
//	std::cin >> num >> index;
//
//	std::cout << isPrimeE(num, index);
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {

	int answer = 0;
	std::vector<int> costs;

	int index = 0;
	int cost = 0;

	for (int i = 0; i < minerals.size(); ++i)
	{
		if (minerals[i] == "diamond")
			cost += 25;
		else if (minerals[i] == "iron")
			cost += 5;
		else
			cost += 1;

		++index;

		if (index == 5)
		{
			costs.push_back(cost);
			cost = 0;
			index = 0;
		}
	}

	if (cost != 0)
		costs.push_back(cost);

	std::sort(costs.begin(), costs.end(), greater<>());

	int fatigue[3][3];

	fatigue[0][0] = 1;
	fatigue[0][1] = 5;
	fatigue[0][2] = 25;
	fatigue[1][0] = 1;
	fatigue[1][1] = 1;
	fatigue[1][2] = 5;
	fatigue[2][0] = 1;
	fatigue[2][1] = 1;
	fatigue[2][2] = 1;

	for (auto& cost : costs)
	{
		int dia = 0;
		int iron = 0;
		int rock = 0;

		if (cost > 25)
		{
			dia = cost / 25;
			cost %= 25;
		}
		if (cost > 5)
		{
			iron = cost / 5;
			cost %= 5;
		}

		rock = cost;


		for (int i = 0; i < 3; ++i)
		{
			if (picks[i] != 0)
			{
				answer += dia * fatigue[0][i];
				answer += iron * fatigue[1][i];
				answer += rock * fatigue[2][i];
				picks[i] -= 1;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	std::vector<int> picks = { 0, 1, 1 };
	std::vector<std::string> minerals = { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" };

	std::cout << solution(picks, minerals);

	return 0;
}
