#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int garbageCollection(vector<string>& garbage, vector<int>& travel)
	{
		int paper = 0;
		int metal = 0;
		int glass = 0;

		int papermove = 0;
		int metalmove = 0;
		int glassmove = 0;

		int moveTimeCheck = 0;

		for (int i = 0; i < garbage.size(); ++i)
		{
			bool getP = false;
			bool getM = false;
			bool getG = false;

			for (int j = 0; j < garbage[i].size(); ++j)
			{
				if (garbage[i][j] == 'G')
				{
					glass += 1;
					getG = true;
				}
				else if (garbage[i][j] == 'P')
				{
					paper += 1;
					getP = true;
				}
				else if (garbage[i][j] == 'M')
				{
					metal += 1;
					getM = true;
				}
			}

			if (getG == true)
			{
				glassmove = moveTimeCheck;
			}
			if (getM == true)
			{
				metalmove = moveTimeCheck;
			}
			if (getP == true)
			{
				papermove = moveTimeCheck;
			}

			if (i == garbage.size() - 1)
			{
				break;
			}

			moveTimeCheck += travel[i];

		}

		return glass + metal + paper + glassmove + metalmove + papermove;
	}
};


int main()
{
	vector<std::string> garbage = { "G", "P", "GP", "GG" };
	vector<int> travel = { 2, 4, 3 };

	Solution sol;
	int an = sol.garbageCollection(garbage, travel);

	return 0;
}
