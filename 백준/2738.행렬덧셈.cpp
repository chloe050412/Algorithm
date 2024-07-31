#include <iostream>
#include <vector>


int row, col = 0;
int A[100][100];
int B[100][100];

int result[100][100];

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> row >> col;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cin >> B[i][j];
		}
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << A[i][j] + B[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}
