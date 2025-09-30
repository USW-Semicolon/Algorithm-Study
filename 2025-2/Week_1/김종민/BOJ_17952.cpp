#include <iostream>
#include <stack>

using PII = std::pair<int, int>;
using Long = long long;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto total_min = 0;
    std::cin >> total_min;

    auto homework_stack = std::stack<PII>();

    auto total_score = Long(0);
    for(auto i = 0; i < total_min; i++)
    {
        auto get_homework_flag = 0;
        std::cin >> get_homework_flag;

        if(get_homework_flag == 1)
        {
            auto homework_info = PII(0, 0);
            std::cin >> homework_info.first >> homework_info.second;

            homework_stack.push(homework_info);
        }

        if(!homework_stack.empty())
        {
            homework_stack.top().second--;

            if(homework_stack.top().second == 0)
            {
                total_score += homework_stack.top().first;
                homework_stack.pop();
            }
        }   
    }

    std::cout << total_score;

    return 0;
}