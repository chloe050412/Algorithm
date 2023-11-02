#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<int> findMode(TreeNode* root)
	{
		vector<int> result;
		unordered_map<int, int> counts;

		Recursive(root, counts);

		int maxCount = INT_MIN;

		for (auto& i : counts)
		{
			if (i.second > maxCount)
			{
				maxCount = i.second;
				result.clear();
				result.push_back(i.first);
			}
			else if (i.second == maxCount)
			{
				result.push_back(i.first);
			}
		}

		return result;
	}

	void Recursive(TreeNode* now, unordered_map<int, int>& result)
	{
		if (now == nullptr)
		{
			return;
		}
			
		result[now->val]++;

		Recursive(now->left, result);
		Recursive(now->right, result);
	}
};

int main()
{


	return 0;
}
