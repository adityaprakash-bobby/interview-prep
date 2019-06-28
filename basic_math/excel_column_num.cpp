#include <iostream>
using namespace std;

/* Function to find the column number from title in a Excel Sheet */
int titleToNumber(string A) {
    
    int col_num = 0;
    
    for (auto i = 0; A[i] != '\0'; i++) {
        col_num = col_num * 26 + (int(A[i]) + 1 - 65);
    }
    
    return col_num;
}

/* Driver to test the function */
int main(int argc, char const *argv[])
{

    string test = "AA";
    cout << titleToNumber(test) << endl;
    return 0;

}