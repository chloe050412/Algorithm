#include <iostream>
#include <queue>

struct Data
{
	int x;
	int y;
	int distance;
};

int main()
{
	// 변수 선언
	int x, y = 0;

	std::string map[100];
	bool visited[100][100] = { false };

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	std::queue<Data> q;
	int shortest_distance = -1;

	// 값 입력
	std::cin >> y >> x;

	for (int i = 0; i < y; ++i)
		std::cin >> map[i];

	// 시작점
	Data start;
	start.x = 0;
	start.y = 0;
	start.distance = 1;

	visited[0][0] = true;

	q.push(start);

	while (!q.empty())
	{
		// current pos
		auto current = q.front();
		q.pop();

		if (current.x == x - 1 && current.y == y - 1)
		{
			shortest_distance = current.distance;
			break;
		}

		for (int k = 0; k < 4; ++k)
		{
			int nextX = current.x + dx[k];
			int nextY = current.y + dy[k];

			// 범위를 벗어나거나 & 갈 수 없는 길이거나 & 이미 방문한 곳일 때
			if (nextX < 0 || nextX >= x ||
				nextY < 0 || nextY >= y ||
				map[nextY][nextX] == '0' ||
				visited[nextY][nextX])
				continue;

			Data next;
			next.x = nextX;
			next.y = nextY;
			next.distance = current.distance + 1;

			visited[nextY][nextX] = true;

			q.push(next);
		}
	}

	std::cout << shortest_distance;

	return 0;
}
