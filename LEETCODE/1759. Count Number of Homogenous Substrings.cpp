#include <unordered_map>
#include <string>
using namespace std;

class Solution 
{
public:
	int countHomogenous(string s) 
	{
		result = 0;
		count = 1;

		for (long long i = 0; i < s.size(); ++i)
		{
			if (s[i] == s[i+1])
			{
				result += count;
				count++;
			}
			else
			{
				result += count;
				count = 1;
			}
		}

		return result;
	}

private:
	long long count;
	long long result;
};

int main()
{
	string  s = "abbcccaa";

	Solution sol;
	int a = sol.countHomogenous(s);

	return 0;
}
