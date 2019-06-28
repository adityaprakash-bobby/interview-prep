#include <iostream>
#include <algorithm>
using namespace std;

/* Function to find the column name from column number in a Excel Sheet */
string numberToTitle(int A) {
    
    string col_name = "";
    int num = A;
    int rem;

    while (num > 0) {
        rem = num%26;
        if (rem == 0) {
            col_name += 'Z';    
            num = num/26 - 1;
        } else {
            col_name += char((num%26 + 64));
            num /= 26;
        }
    }
    reverse(col_name.begin(), col_name.end());

    return col_name;

}

/* Driver to test the function */
int main(int argc, char const *argv[])
{

    int col_num = 943566;
    cout << numberToTitle(col_num) << endl;
    return 0;

}