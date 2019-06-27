#include <iostream>
#include <vector>
using namespace std;

/* Function to print FizzBuzz */
vector<string> print_fizz_buzz(int A) {

    vector<string> result;
    
    for (int i = 1; i <= A; i++) {

        if (i%3 == 0 && i%5 == 0) {
            result.push_back("FizzBuzz");
        } else if (i%3 == 0) {
            result.push_back("Fizz");
        } else if (i%5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
         
    }

    return result; 
}

/* Driver to test Fizz Buzz */
int main(int argc, char const *argv[])
{
    int number = 200;
    vector<string> result = print_fizz_buzz(number);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
