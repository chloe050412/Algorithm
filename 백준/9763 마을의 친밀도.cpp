#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

int countryCount;

struct cityPos
{
	int x;
	int y;
	int z;
};

inline int distance(cityPos a, cityPos b)
{
	return std::abs(a.x - b.x) + std::abs(a.y - b.y) + std::abs(a.z - b.z);
}

int main()
{
	std::vector<cityPos> townPos;
	int minDistance = 40000;

	// data
	std::cin >> countryCount;

	for (int i = 0; i < countryCount; ++i)
	{
		int posX, posY, posZ;
		std::cin >> posX >> posY >> posZ;

		townPos.push_back({ posX, posY, posZ });
	}

	/// /////////

	for (int i = 0; i < townPos.size(); i++)
	{
		int a = 987654321;
		int b = 987654321;
		for (int j = 0; j < townPos.size(); j++)
		{
			if (i == j)
				continue;

			int c = distance(townPos[i], townPos[j]);

			if (b > c)
			{
				b = c;
				if (a > b)
					std::swap(a, b);
			}
		}

		minDistance = std::min(minDistance, a + b);
	}

	std::cout << minDistance;

	return 0;
}

//int distance(cityPos a, cityPos b, cityPos c)
//{
//	int ab = std::abs(a.x - b.x) + std::abs(a.y - b.y) + std::abs(a.z - b.z);
//	int bc = std::abs(b.x - c.x) + std::abs(b.y - c.y) + std::abs(b.z - c.z);
//
//	return ab + bc;
//}

//int main()
//{
//	std::vector<cityPos> townPos;
//	int minDistance = 4000;
//
//	// data
//	std::cin >> countryCount;
//
//	for (int i = 0; i < countryCount; ++i)
//	{
//		int posX, posY, posZ;
//		std::cin >> posX >> posY >> posZ;
//
//		townPos.push_back({ posX, posY, posZ });
//	}
//
//	for (int i = 0; i < townPos.size() - 2; ++i)
//	{
//		for (int j = i + 1; j < townPos.size() - 1; ++j)
//		{
//			for (int k = j + 1; k < townPos.size(); ++k)
//			{
//				minDistance = std::min(distance(townPos[i], townPos[j], townPos[k]), minDistance);
//			}
//		}
//	}
//
//	std::cout << minDistance;
//
//	return 0;
//}
