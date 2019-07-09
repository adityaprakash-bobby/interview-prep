#include <iostream>
#include <vector>
using namespace std;

int appearOnce(vector<int> A) {

    int x = A[0];

    for (int i = 1; i < A.size(); i++) {
        x = x^A[i];
    }

    return x;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 3, 3, 1, 4};
    cout << appearOnce(A) << endl;
    return 0;
}