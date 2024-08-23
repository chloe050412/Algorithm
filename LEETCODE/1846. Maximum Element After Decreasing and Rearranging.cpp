#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());

		arr[0] = 1;

		int result = 1;
		for (auto& num : arr)
		{
			std::min(result + 1, num);
		}

		return result;
	}
};

int main()
{
	vector<int> arr = { 712704514,545918790,115890310,835846393,175769706,559353362,901891104,422254447 };

	Solution sol;
	sol.maximumElementAfterDecrementingAndRearranging(arr);

	

	return 0;
}
