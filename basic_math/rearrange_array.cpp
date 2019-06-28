#include <iostream>
#include <vector>
using namespace std;

/* Function to replace A[i] with A[A[i]] */
void arrange(vector<int> &A) {
    
    int size = A.size();
    
    for (auto i = 0; i < size; i++) {
        A[i] += (A[A[i]] % size) * size;
    }
    
    for (auto i = 0; i < size; i++) {
        A[i] /= size;
    }
    
}

/* Driver for the above function */
int main(int argc, char const *argv[])
{
    vector<int> arr = {5 , 4, 1, 2, 3, 0};
    arrange(arr);
    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << " ";
    }

    return 0;
}
