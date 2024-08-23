#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution
{
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums)
	{
		vector<int> res;
		queue<pair<int, int>> q;
		q.push({ 0, 0 });

		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			res.push_back(nums[p.first][p.second]);

			if (p.second == 0 && p.first + 1 < nums.size()) {
				q.push({ p.first + 1, 0 });
			}

			if (p.second + 1 < nums[p.first].size()) {
				q.push({ p.first, p.second + 1 });
			}
		}

		return res;
	}
};

int main()
{
	vector<vector<int>> nums = { {1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16} };

	Solution sol;
	auto a = sol.findDiagonalOrder(nums);

	return 0;
}

