#include <iostream>
#include <vector>
using namespace std;

//int solution(vector<vector<int> > land)
//{
//	int answer = 0;
//	int before = 5;
//	int now = 0;
//	int max = 0;
//
//	for (int i = 0; i < land.size(); ++i)
//	{
//		max = 0;
//
//		for (int j = 0; j < 4; ++j)
//		{
//			if (land[i][j] > max)
//			{
//				if (j == before)
//				{
//					continue;
//				}
//				max = land[i][j];
//				now = j;
//			}
//		}
//
//		before = now;
//		answer += max;
//	}
//	return answer;
//}

int findMax(int a, int b, int c, int d = 0)
{
	int max = a;

	if (b > max)
	{
		max = b;
	}

	if (c > max)
	{
		max = c;
	}

	if (d > max)
	{
		max = d;
	}

	return max;
}

int solution(vector<vector<int>> land)
{
	int answer = 0;
	int lastIndex = land.size() - 1;

	for (int i = 1; i < land.size(); ++i)
	{
		land[i][0] += findMax(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
		land[i][1] += findMax(land[i - 1][0], land[i - 1][2], land[i - 1][3]);
		land[i][2] += findMax(land[i - 1][0], land[i - 1][1], land[i - 1][3]);
		land[i][3] += findMax(land[i - 1][0], land[i - 1][1], land[i - 1][2]);
	}

	answer = findMax(land[lastIndex][0], land[lastIndex][1], land[lastIndex][2], land[lastIndex][3]);

	return answer;
}

int main()
{
	vector<vector<int>> r = { {6, 7, 1, 2}, {2, 3, 10, 8}, {1, 3, 9, 4}, {7, 11, 4, 9} };
	int t = solution(r);

	return 0;
}
