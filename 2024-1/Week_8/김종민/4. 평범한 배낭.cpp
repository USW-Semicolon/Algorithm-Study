#include <iostream>
#include <vector>
#include <array>

int dp[101][100001];

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto item_count = 0, max_kg = 0;
    std::cin >> item_count >> max_kg;

    std::vector<std::pair<int, int>> items(item_count + 1);
    for (auto i = 1; i <= item_count; i++)
        std::cin >> items[i].first >> items[i].second;

    for (auto count = 1; count <= item_count; count++)
        for (auto limit = 1; limit <= max_kg; limit++)
        {
            if (items[count].first > limit)
                dp[count][limit] = dp[count - 1][limit];
            else
                dp[count][limit]
                = std::max(
                    dp[count - 1][limit - items[count].first] + items[count].second
                    , dp[count - 1][limit]);
        }

    std::cout << dp[item_count][max_kg];

    return 0;
}