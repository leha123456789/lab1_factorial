#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
int main() 
{
    std::mutex mtx; 
    long long factorial_result = 1; 
    auto calculateFactorialRange = [&](int start, int end, long long& result) 
    {
        long long local_result = 1;
        for (int i = start; i <= end; ++i) 
        {
            local_result *= i;
        }
        result = local_result;
    };
    auto measureExecutionTime = [&](int num_threads) 
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        const int number = 20; 
        std::vector<long long> results(num_threads);
        std::thread threads[num_threads];
        int chunk_size = number / num_threads;
        int start = 1;
        int end = chunk_size;
        for (int i = 0; i < num_threads; ++i) 
        {
            threads[i] = std::thread(calculateFactorialRange, start, end, std::ref(results[i]));
            start = end + 1;
            end = (i == num_threads - 2) ? number : end + chunk_size;
        }
        for (int i = 0; i < num_threads; ++i) 
        {
            threads[i].join();
        }
        factorial_result = 1;
        for (long long res : results) 
        {
            factorial_result *= res;
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        std::cout << "Время выполнения с " << num_threads << " потоками: " << elapsed.count() << std::endl;
        return elapsed.count();
    };
    double min_time = std::numeric_limits<double>::max();
    int optimal_threads = 0;
    for (int num_threads = 1; num_threads <= 32; num_threads *= 2) 
    {
        double execution_time = measureExecutionTime(num_threads);
        if (execution_time < min_time) 
        {
            min_time = execution_time;
            optimal_threads = num_threads;
        }
    }
    std::cout << "Наименьшее время выполнения: " << min_time << " секунд" << std::endl;
    std::cout << "Оптимальное количество потоков: " << optimal_threads << std::endl;
    const int number = 20;
    std::cout << "Факториал " << number << " равен: " << factorial_result << std::endl;
    return 0;
}
