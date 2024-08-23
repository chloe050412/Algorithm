#include <cmath>

class Solution 
{
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
	{
		int x = std::abs(fx - sx);
		int y = std::abs(fy - sy);

		if ((x == 0 && y == 0) && t == 1)
		{
			return false;
		}
		return (x <= t && y <= t);
	}


};