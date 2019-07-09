#include <iostream>

using namespace std;

/* Function to reverse a 32 bit unsigned integer */
uint rev32bitNum(uint &A) {

    uint res = 0;
    int i = 32;

    while (i--) {
        
        if (A & 1 == 1) {
            res = res | 1;
        } 

        if (i > 0) {
            res = res << 1;
        }

        A = A >> 1;

    }

    return res;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    uint num = 3;
    cout << rev32bitNum(num) << endl;   
    return 0;
}