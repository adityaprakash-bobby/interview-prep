#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#define fo(i, a ,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a ,b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Add binary numbers in string */
string addBinary(string a, string b) {

    string c;
    int ptr_a = a.size() - 1;
    int ptr_b = b.size() - 1;
    int rem = 0, carry = 0;

    while (ptr_a >= 0 || ptr_b >= 0) {

        if (ptr_a >=0 && ptr_b >= 0) {

            rem = ((int)(a[ptr_a] - '0') + (int)(b[ptr_b] - '0') + carry)%2;
            carry = ((int)(a[ptr_a] - '0') + (int)(b[ptr_b] - '0') + carry)/2;
            // cout << "Carry " << carry << " Res " << rem << endl;
        
        } else if (ptr_a >= 0 && ptr_b < 0) {
        
            rem = ((int)(a[ptr_a] - '0') + carry)%2;
            carry = ((int)(a[ptr_a] - '0') + carry)/2;
            // cout << "Carry " << carry << " Res " << rem << endl;
        
        } else if (ptr_b >= 0 && ptr_a < 0) {
        
            rem = ((int)(b[ptr_b] - '0') + carry)%2;
            carry = ((int)(b[ptr_b] - '0') + carry)/2;
            // cout << "Carry " << carry << " Res " << rem << endl;
    
        }
        
        c.insert(c.begin(), '0' + rem);

        ptr_a--;
        ptr_b--;
    
    }

    // cout << "End carry = " << carry << endl;

    if (carry > 0) {
        c.insert(c.begin(), '1');
    }

    return c;
}

/* Driver to test the function */
int main(int argc, char const *argv[])
{
    string a = "1010110111001101101000", b="1000011011000000111100110";
    cout << addBinary(a, b) << endl;   
    return 0;
}