#include <iostream>

using namespace std;

/* Function to check palindrome integer */
int is_palindrome(int A) {

    if (A < 0) {
        return 0;
    }

    int temp = A, rev = 0, rem = 0;
    while (temp > 0) {

        rem = temp % 10;
        rev = rev*10 + rem;
        temp /= 10;
    
    }
    
    if (A != rev) {
        return 0;
    } else {
        return 1;    
    }

}

/* Driver to check palindrome */
int main(int argc, char const *argv[])
{
    int number = 111121111;
    cout << is_palindrome(number);
    return 0;
}
