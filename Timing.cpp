#include <iostream>
#include <chrono>
#include <thread>


struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};

void function()
{
    Timer timer;

    for (int i = 0; i < 1000; i++)
        std::cout << "Hello\n";
}

int main()
{
    function();
    // using namespace std::literals::chrono_literals;
    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end = std::chrono::high_resolution_clock::now();
 
    // std::chrono::duration<float> duration = end - start;
    // std::cout << duration.count() << "s" << std::endl;

}