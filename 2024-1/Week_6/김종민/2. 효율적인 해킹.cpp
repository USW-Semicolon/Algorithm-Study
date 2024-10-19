#include <iostream>
#include <vector>
#include <algorithm>

void Hacking(const std::vector<std::vector<int>>& link, std::vector<bool>& visit, int computer, int& count)
{
	visit[computer] = true;

	for (auto component : link[computer])
		if (!visit[component])
		{
			count++;
			Hacking(link, visit, component, count);
		}
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0, M = 0;
	std::cin >> N >> M;

	auto graph = std::vector<std::vector<int>>(N + 1, std::vector<int>());
	for (auto i = 0; i < M; i++)
	{
		auto from = 0, to= 0;
		std::cin >> from >> to;

		graph[to].push_back(from);
	}

	auto can_hacking = std::vector<int>(N + 1);
	for (auto i = 1; i <= N; i++)
	{
		auto is_hacked = std::vector<bool>(N + 1);

		auto count = 0;
		Hacking(graph, is_hacked, i, count);
		can_hacking[i] = count;
	}

	auto max_hacking_count = *std::max_element(can_hacking.begin(), can_hacking.end());

	auto answer_vec = std::vector<int>();
	for (auto i = 1; i <= N; i++)
		if (can_hacking[i] == max_hacking_count)
			answer_vec.push_back(i);

	std::sort(answer_vec.begin(), answer_vec.end());
	for (const auto& answer : answer_vec)
		std::cout << answer << " ";

	return 0;
}