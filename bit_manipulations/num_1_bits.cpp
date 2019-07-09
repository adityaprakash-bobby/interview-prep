#include <iostream>

using namespace std;

/* Function to return the number of 1 bits in an unsigned 32-bit number */
int numOneBits(uint &A) {

    int count_1s = 0;

    while (A > 0) {
        
        if (A & 1 == 1) {
            count_1s++;
        }

        A = A >> 1;

    }

    return count_1s;
}

/* Driver function to test the above */
int main(int argc, char const *argv[])
{

    uint num = 11;

    cout << numOneBits(num) << endl;

    return 0;
}