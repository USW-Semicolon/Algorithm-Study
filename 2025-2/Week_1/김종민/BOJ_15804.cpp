#include <iostream>
#include <deque>

struct Bus
{
    int arrive_time;
    int depart_time;
    int stop_position;

    Bus(int arrive_time, int depart_time, int stop_position)
    {
        this->arrive_time = arrive_time;
        this->depart_time = depart_time;
        this->stop_position = stop_position;
    }
};

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto bus_stop_length = 0;
    auto simulation_count = 0;
    std::cin >> bus_stop_length >> simulation_count;

    auto bus_deq = std::deque<Bus>();

    for(auto i = 0; i < simulation_count; i++)
    {
        auto arrive_time = 0;
        auto depart_time = 0;
        std::cin >> arrive_time >> depart_time;

        while(!bus_deq.empty() && arrive_time >= bus_deq.front().depart_time)
            bus_deq.pop_front();

        if(bus_deq.empty())
            bus_deq.push_back(Bus(arrive_time, arrive_time + depart_time, 1));
        else if(bus_deq.back().stop_position < bus_stop_length)
        {
            arrive_time = std::max(arrive_time, bus_deq.back().arrive_time);
            bus_deq.push_back(Bus(arrive_time, arrive_time + depart_time, bus_deq.back().stop_position + 1));
        }
        else
        {
            while(!bus_deq.empty())
            {
                arrive_time = std::max(arrive_time, bus_deq.front().depart_time);
                bus_deq.pop_front();
            }

            bus_deq.push_back(Bus(arrive_time, arrive_time + depart_time, 1));
        }
    }

    std::cout << bus_deq.back().stop_position;

    return 0;
}