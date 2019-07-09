#include <iostream>
#include <vector>
using namespace std;

/* Function to return the number in array which occurs only once */
int appearOnce(vector<int> A) {

    int x = A[0];

    for (int i = 1; i < A.size(); i++) {
        x = x^A[i];
    }

    return x;
}

/* Driver function to test the above function */
int main(int argc, char const *argv[])
{
    vector<int> A = {1, 3, 3, 1, 4};
    cout << appearOnce(A) << endl;
    return 0;
}