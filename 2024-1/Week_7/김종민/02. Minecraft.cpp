#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto n = 0;
	std::cin >> n;

	auto projection3 = std::vector<std::vector<std::vector<char>>>(3, std::vector<std::vector<char>>(n, std::vector<char>(n, '0')));
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < n; j++)
			for(auto k = 0; k < n; k++)
				std::cin >> projection3[i][j][k];

	auto non_projection3 = std::vector<std::vector<std::vector<char>>>(3, std::vector<std::vector<char>>(n, std::vector<char>(n, '0')));
	auto matrix_nbyn = std::vector<std::vector<std::vector<char>>>(n, std::vector<std::vector<char>>(n, std::vector<char>(n, '0')));
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j++)
			if (projection3[0][i][j] == '1')
			{
				auto check = false;

				for (auto k = 0; k < n; k++)
					if (projection3[1][k][i] == '1' and projection3[2][k][j] == '1')
					{
						check = true;
						matrix_nbyn[k][i][j] = '1';
					}

				if (!check)
				{
					std::cout << "NO";
					return 0;
				}
			}

	for (auto j = 0; j < n; j++)
		for (auto k = 0; k < n; k++)
			if(projection3[0][j][k] != matrix_nbyn[0][j][k])
			{
				std::cout << "NO";
				return 0;
			}

	for (auto j = 0; j < n; j++)
		for (auto k = 0; k < n; k++)
			if(projection3[1][j][k] != matrix_nbyn[j][0][k])
			{
				std::cout << "NO";
				return 0;
			}

	for (auto j = 0; j < n; j++)
		for (auto k = 0; k < n; k++)
			if (projection3[2][j][k] != matrix_nbyn[j][k][0])
			{
				std::cout << "NO";
				return 0;
			}

	std::cout << "YES\n";
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j++)
		{
			for (auto k = 0; k < n; k++)
				std::cout << matrix_nbyn[i][j][k];

			std::cout << '\n';
		}

	return 0;
}