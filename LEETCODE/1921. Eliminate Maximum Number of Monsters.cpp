#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// �Ÿ��� �ӵ��� 1 �̻� 50�� ����
// ���� ���� 50�� ����
// ���Ϳ� �ӵ��� 1�� 1 ������

class Solution
{
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed)
	{
		int kill = 0;

		for (int i = 0; i < dist.size(); ++i)
		{
			int step = (dist[i]-1) / speed[i] + 1;
			//if (dist[i] % speed[i] > 0)
			//{
			//	step++;
			//}
			count.push_back(step);
		}

		std::sort(count.begin(), count.end());

		for (int i = 0; i < count.size(); ++i)
		{
			if (i >= count[i])
			{
				break;
			}
			++kill;
		}

		return kill;
	}

private:
	vector<int> count;
};


int main()
{
	std::vector<int> dist = { 5, 3, 2 };
	std::vector<int> speed = { 7, 4, 1};

	Solution sol;
	int result = sol.eliminateMaximum(dist, speed);

	return 0;
}