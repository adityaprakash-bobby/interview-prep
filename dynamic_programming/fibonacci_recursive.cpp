#include <iostream>
#define fo(i, n) for(i = 0; i < n; i++)

/* Recursive program for fibonacci */
int fibo(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n-1) + fibo(n-2);
    }

}

/* Driver for testing the fibonacci series function */
int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::cout << fibo(n) << std::endl;

    return 0;
}
