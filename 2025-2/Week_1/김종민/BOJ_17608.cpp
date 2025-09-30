#include <cstdint>
#include <iostream>
#include <stack>

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto stick_count = 0;
    std::cin >> stick_count;

    auto stick_stack = std::stack<int>();
    stick_stack.push(INT32_MIN);
    for(auto i = std::size_t(0); i < stick_count; i++)
    {
        auto temp_stick = 0;
        std::cin >> temp_stick;

        while(!stick_stack.empty() && stick_stack.top() <= temp_stick)
            stick_stack.pop();

        stick_stack.push(temp_stick);
    }

    std::cout << stick_stack.size();

    return 0;
}

