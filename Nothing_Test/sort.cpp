#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <execution>
#include <random>

// Function to generate a random vector of given size
std::vector<int> generateRandomVector(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = dis(gen);
    }
    return vec;
}

int main()
{
    // Set the size of the vector
    int vectorSize = 100000000; // Adjust this as needed

    // Generate random vector
    std::vector<int> vec = generateRandomVector(vectorSize);
    std::vector<int> vec_origin(vec);
    std::cout << "Testing std::sort(std::execution::par_unseq)...\n";
    auto start = std::chrono::steady_clock::now();
    std::sort(std::execution::par_unseq, vec.begin(), vec.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Sorting time: " << elapsed_seconds.count() << "s\n";
    std::vector<int> vec2 = vec_origin;

    std::cout << "\nTesting std::sort(std::execution::par)...\n";
    auto start2 = std::chrono::steady_clock::now();
    std::sort(std::execution::par, vec2.begin(), vec2.end());
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    std::cout << "Sorting time: " << elapsed_seconds2.count() << "s\n";
    std::vector<int> vec3 = vec_origin;
    std::cout << "\nTesting std::sort()...\n";
    auto start3 = std::chrono::steady_clock::now();
    std::sort(vec3.begin(), vec3.end());
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
    std::cout << "Sorting time: " << elapsed_seconds3.count() << "s\n";
    return 0;
}
