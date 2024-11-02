#include <iostream>
#include <vector>
#include <queue>

using PII = std::pair<int, int>;

auto col = 0, row = 0;
auto map = std::vector<std::vector<char>>();
auto visit = std::vector<std::vector<int>>();
auto start = PII();

auto que = std::queue<PII>();
auto dx = std::vector<int>{ 1, -1, 0, 0 };
auto dy = std::vector<int>{ 0, 0, 1, -1 };

auto building = 0;
auto breaked = 0;

void propagate(int y, int x, int range)
{
	for (auto i = 0; i < 4; i++)
		for (auto j = 1; j <= range; j++)
		{
			auto ny = y + dy[i] * j;
			auto nx = x + dx[i] * j;

			if (nx < 0 or ny < 0 or nx >= row or ny >= col)
				break;

			if (map[ny][nx] == '|')
				break;

			visit[ny][nx]++;

			if ((map[ny][nx] == '*' and visit[ny][nx] == 1) or
				(map[ny][nx] == '#' and visit[ny][nx] == 2))
				que.push(std::make_pair(ny, nx));
		}
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	std::cin >> col >> row;

	map = std::vector<std::vector<char>>(col, std::vector<char>(row));
	visit = std::vector<std::vector<int>>(col, std::vector<int>(row));

	for (auto i = 0; i < col; i++)
		for (auto j = 0; j < row; j++)
		{
			std::cin >> map[i][j];

			if (map[i][j] == '@')
				start = std::make_pair(i, j);

			if (map[i][j] == '*' or map[i][j] == '#')
				building++;
		}

	propagate(start.first, start.second, 2);

	while (!que.empty())
	{
		propagate(que.front().first, que.front().second, 1);
		que.pop();
	}

	for (auto i = 0; i < col; i++)
		for (auto j = 0; j < row; j++)
			if ((map[i][j] == '*' and visit[i][j] >= 1) or
				(map[i][j] == '#' and visit[i][j] >= 2))
			{
				building--;
				breaked++;
			}

	std::cout << breaked << " " << building;

	return 0;
}