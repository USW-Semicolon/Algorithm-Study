#include <iostream>
#include <vector>
#include <string>

using PII = std::pair<int, int>;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto n = 0;
    std::cin >> n;

    auto check = std::vector<bool>(1000);
    for (auto i = 123; i <= 987; i++)
    {
        auto str = std::to_string(i);

        if (str[0] == str[1] or str[1] == str[2] or str[2] == str[0])
            check[i] = true;

        if (str[0] == '0' or str[1] == '0' or str[2] == '0')
            check[i] = true;
    }

    auto num = 0, strike = 0, ball = 0;
    auto t_strike = 0, t_ball = 0;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> num >> strike >> ball;

        for (auto i = 123; i <= 987; i++)
        {
            t_strike = 0;
            t_ball = 0;

            if (!check[i])
            {
                for (auto j = 0; j < 3; j++)
                    for (auto k = 0; k < 3; k++)
                    {
                        if (j == k and std::to_string(num)[j] == std::to_string(i)[k])
                            t_strike++;

                        if (j != k and std::to_string(num)[j] == std::to_string(i)[k])
                            t_ball++;
                    }

                if (strike != t_strike or ball != t_ball)
                    check[i] = true;
            }
        }
    }

    auto answer = 0;
    for (auto i = 123; i <= 987; i++)
        if (!check[i])
            answer++;

    std::cout << answer;

    return 0;
}