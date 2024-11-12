#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

auto size = 0;
auto count = 0;

auto map = std::vector<std::vector<int>>(25, std::vector<int>(25));
auto check = std::vector<std::vector<int>>(25, std::vector<int>(25));

auto dx = std::vector<int>{ 1, -1, 0, 0 };
auto dy = std::vector<int>{ 0, 0, 1, -1 };

auto answer_vec = std::vector<int>();
auto answer_count = 0;

void dfs(int x, int y)
{
    count++;
    check[x][y] = true;

    for (auto i = 0; i < 4; i++)
    {
        auto nx = x + dx[i];
        auto ny = y + dy[i];

        if (nx < 0 or nx > size - 1 or ny < 0 or ny > size - 1)
            continue;

        if (!check[nx][ny] and map[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> size;

    for (auto i = 0; i < size; i++)
        for (auto j = 0; j < size; j++)
        {
            char num;
            std::cin >> num;
            map[i][j] = num - '0';
        }

    for (auto i = 0; i < size; i++)
        for (auto j = 0; j < size; j++)
            if (map[i][j] != 0)
                if (!check[i][j])
                {
                    count = 0;
                    dfs(i, j);
                    answer_vec.push_back(count);
                    answer_count++;
                }

    std::sort(answer_vec.begin(), answer_vec.end());

    std::cout << answer_count << std::endl;
    for (auto element : answer_vec)
        std::cout << element << std::endl;

    return 0;
}