#include <iostream>
#include <queue>
using namespace std;

int row, col, sheep, wolf, r_wolf, r_sheep;
string farm[252];
bool check[252][252] = { false };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> row >> col;

	for (int i = 0; i < row; ++i)
		cin >> farm[i];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (farm[i][j] != '#' && check[i][j] == false)
			{
				wolf = 0;
				sheep = 0;

				q.push({ i, j });
				check[i][j] = true;

				if (farm[i][j] == 'v') wolf++;
				else if (farm[i][j] == 'o') sheep++;

				while (!q.empty())
				{
					// 첫 번째 노드를 탐색한다
					auto cur = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
						else if (check[nx][ny] == true || farm[nx][ny] == '#') continue;

						if (farm[nx][ny] == 'v') wolf++;
						else if (farm[nx][ny] == 'o') sheep++;

						check[nx][ny] = true;
						q.push({ nx, ny });

					}
				}

				if (wolf >= sheep) r_wolf += wolf;
				else r_sheep += sheep;

			}

		}
	}

	cout << r_sheep << " " << r_wolf;


	return 0;
}
