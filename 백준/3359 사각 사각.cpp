#include <iostream>
#include <vector>
#include <queue>

int rectCount;

struct data
{
	int width;
	int height;

	int accumulateSize;
};

std::vector<data> datas;

int main()
{
	// input
	std::cin >> rectCount;
	
	int w, h;

	for (int i = 0; i < rectCount; ++i)
	{
		std::cin >> w >> h;

		datas.push_back({ w, h, 0 });
	}

	std::queue<data> q;
	int result = 0;

	// 첫 값은 가로 세로 버전 두 개
	datas.front().accumulateSize = datas.front().width;
	q.push(datas.front());

	datas.front().accumulateSize = datas.front().height;
	q.push(datas.front());

	for (int i = 2; i < datas.size(); ++i)
	{
		while (!q.empty())
		{
			auto now = q.front();
			q.pop();

			if (result < now.accumulateSize)
			{
				result = now.accumulateSize;
			}


		}
	}


	return 0;
}
