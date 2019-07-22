#include <iostream>
#include <vector>

using namespace std;

/* Function to return the array of digits adding 1 to the number formed by it */
vector<int> plusOne(vector<int> &A) {

    int ptr = A.size() - 1;
    int carry = 1;
    
    while (carry == 1 && ptr >= 0) {

        int temp = A[ptr] + 1;

        A[ptr] = temp % 10;
        carry = temp / 10;

        ptr--;

    }

    if (carry == 1) {
        A.insert(A.begin(), 1);
    }
    
    // Remove any leading 0s
    while (*A.begin() == 0) {
        A.erase(A.begin());
    }
    
    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {0, 3, 5, 4, 6, 6};
    vector<int> res = plusOne(test);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}