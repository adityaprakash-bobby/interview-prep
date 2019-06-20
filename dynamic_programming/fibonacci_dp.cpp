#include <iostream>
#define fo(i, n) for(i = 0; i < n; i++)

/* Dynamic program for fibonacci series */
int fibo(int n) {

    int i = 0;
    int mem[n+2];

    mem[0] = 0;
    mem[1] = 1;

    for (auto i = 2; i <= n; i++) {
        mem[i] = mem[i-1] + mem[i-2];
    }

    return mem[n];
}

/* Driver for testing the fibonacci series function */
int main(int argc, char const *argv[])
{
    int n;
    int it = 0;
    
    std::cin >> n;
    std::cout << fibo(n) << std::endl;

    return 0;
}