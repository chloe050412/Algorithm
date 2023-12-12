#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/// �� ����. �ð� �ʰ��� ����.

//class Solution 
//{
//public:
//	int countNicePairs(vector<int>& nums) 
//	{
//		int count = 0;
//		vector<int> revs;
//		
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			std::string oneNum = std::to_string(nums[i]);
//			std::reverse(oneNum.begin(), oneNum.end());
//
//			// ������ ����� ��Ƶΰ�
//			revs.push_back(std::stoi(oneNum));
//		}
//
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			for (int j = i + 1; j < nums.size(); ++j)
//			{
//				if (nums[i] + revs[j] == nums[j] + revs[i]) ++count;
//			}
//		}
//
//		return count;
//	}
//};


/// <summary>
///  ���� ����. ���߿� ������ ����.
/// </summary>

class Solution
{
public:
	int countNicePairs(vector<int>& nums)
	{
		std::unordered_map<int, int> count;
		const int mod = 1e9 + 7;
		int res = 0;

		for (const auto& one : nums)
		{
			int r = rev(one);
			int cur = count[one - r];
			count[one - r] = cur + 1;


			res = (res + cur) % mod;
		}

		return res;
	}

private:
	int rev(int num)
	{
		int result = 0;

		while (num > 0)
		{
			int mod = num % 10;
			result = result * 10 + mod;
			num /= 10;
		}

		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> num = { 42,11,1,97 };

	auto answer = sol.countNicePairs(num);

	return 0;
}
