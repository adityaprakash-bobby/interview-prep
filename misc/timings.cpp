#include <iostream>
#include <vector>
#include <chrono>

struct Timer {
    
    std::chrono::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "The duration of run = " << ms << "ms.\n";
    }

};

void pushUtil() {
    
    Timer timer;
    std::vector<int> testVector;
    for (int i = 0; i < 100000; i++) {
        testVector.push_back(i);
    }
}

int main(int argc, char const *argv[])
{
    printUtil();   
    return 0;
}