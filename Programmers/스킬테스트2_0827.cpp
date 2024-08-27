#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[100001];

int solution(int n)
{
	int answer = 0;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = (arr[i - 2] + arr[i - 1]) % 1234567;
	}

	answer = arr[n];
	
	return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution2(vector<int> citations)
{
	int answer = 0;

	std::sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); ++i)
	{
		if (citations[i] > citations.size() - i)
			break;

		answer = citations[i];
	}

	if (answer == 0 && *citations.begin() != 0)
	{
		answer = *citations.begin();
	}

	return answer;
}

int main()
{
	std::vector<int> test = { 7, 64, 78, 35, 49, 8 };
	std::cout << solution2(test);
	return 0;
}