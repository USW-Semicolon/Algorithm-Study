#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0, S = 0, M = 0;
	std::cin >> N >> S >> M;

	auto music_vol = std::vector<int>(N);
	for (auto i = 0; i < N; i++)
		std::cin >> music_vol[i];

	auto dp = std::vector<std::vector<bool>>(N + 1, std::vector<bool>(M + 1, false));
	dp[0][S] = true;

	for(auto i = 0; i < N; i++)
		for (auto j = 0; j <= M; j++)
			if (dp[i][j])
			{
				if (0 <= j - music_vol[i])
					dp[i + 1][j - music_vol[i]] = true;

				if (M >= j + music_vol[i])
					dp[i + 1][j + music_vol[i]] = true;
			}

	auto max_vol = -1;
	for (auto i = 0; i <= M; i++)
		if (dp[N][i])
			max_vol = std::max(max_vol, i);

	std::cout << max_vol;
	return 0;
}