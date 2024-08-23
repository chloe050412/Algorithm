#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
	int answer = 1;

	// 도착 지점
	int arrive_x = maps.size() - 1;
	int arrive_y = maps[0].size() - 1;

	// 뭔가 하나 더 필요함 
	queue<std::pair<int, int>> _visitable;

	_visitable.push(make_pair(0, 0));

	while (_visitable.empty() == false)
	{
		pair<int, int> point = _visitable.front();
		_visitable.pop();
		
		int route = 0;

		int& x = point.first;
		int& y = point.second;

		// 도착 지점인지 체크
		if (x == arrive_x && y == arrive_y)
		{
			return answer;
		}

		// 한번 갔던 길은 막기
		maps[x][y] = 0;

		// 갈 수 있는 곳 체크
		if (x + 1 <= arrive_x && maps[x + 1][y] == 1)
		{
			_visitable.push(make_pair(x+1, y));
			++route;
		}
		if (y + 1 <= arrive_y && maps[x][y + 1] == 1)
		{
			_visitable.push(make_pair(x, y + 1));
			++route;
		}
		if (x - 1 >= 0 && maps[x - 1][y] == 1)
		{
			_visitable.push(make_pair(x - 1, y));
			++route;
		}
		if (y - 1 >= 0 && maps[x][y - 1] == 1)
		{
			_visitable.push(make_pair(x, y - 1));
			++route;
		}

		// 진영에 도착할 수 없는 경우
		if (route == 0)
		{
			return -1;
		}

		

		answer += route;
	}

	return answer;
}


int main()
{
	vector<vector<int>> test = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };

	int t = solution(test);
	std::cout << t << std::endl;

	return 0;
}
