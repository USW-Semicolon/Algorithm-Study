#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto big = 0, small = 0, lim_b = 0, lim_s = 0;
    std::cin >> big >> small >> lim_b >> lim_s;

    if (big < small)
    {
        std::swap(big, small);
        std::swap(lim_b, lim_s);
    }

    if (big == 0 or lim_b == 0)
    {
        std::cout << std::min(small, lim_s);
        return 0;
    }

    if (small == 0 or lim_s == 0)
    {
        std::cout << std::min(big, lim_b);
        return 0;
    }

    auto answer = 0;
    for (auto i = 1; i <= lim_s; i++)
    {
        auto space = (small / i) + 1;

        if (big < space)
            answer = std::max(answer, (space - 1) * 2);
        else if (big == space)
            answer = std::max(answer, big + (space - 1));
        else
            answer = std::max(answer, std::min(space * lim_b, big) + (space - 1));
    }
    std::cout << answer;

    return 0;
}