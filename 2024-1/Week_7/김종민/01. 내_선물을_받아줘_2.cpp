#include <iostream>
#include <vector>

auto map = std::vector<char>(1000);
auto parent = std::vector<int>(1000);

int Find(int vertex)
{
	if (parent[vertex] == vertex)
		return vertex;
	return parent[vertex] = Find(parent[vertex]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		parent[b] = a;
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto map_size = 0;
	std::cin >> map_size;

	for (auto i = 0; i < map_size; i++)
	{
		std::cin >> map[i];
		parent[i] = i;
	}

	for (auto i = 0; i < map_size; i++)
	{
		auto next_idx = (map[i] == 'E') ? i + 1 : i - 1;

		if (next_idx >= 0 and next_idx < map_size)
			Union(i, next_idx);
	}

	auto gift_count = 0;
	for (auto i = 0; i < map_size; i++)
		if (Find(i) == i)
			gift_count++;

	std::cout << gift_count;

	return 0;
}