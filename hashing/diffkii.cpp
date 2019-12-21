#include <iostream>
#include <vector>
#include <algorithm>

/*
    Function to return if a pair of number exixts whose difference is equal to
    B in the vector of integers in A. If present, return 1 else 0.
*/
int diffK(const std::vector<int> &A, const int &B) {

    std::vector<int> temp;
    temp.assign(A.begin(), A.end());

    sort(temp.begin(), temp.end());

    int i = 0, j = 1, diff;

    while (j < temp.size()) {
        diff = temp[j] - temp[i];

        if (diff < B)
            j++;
        else if (diff > B)
            i++;
        else 
            return 1;

        if (i == j) 
            j++;
    }

    return 0;
}

/* Driver to test the above function */
int main(int argc, char const *argv[]) {
    std::vector<int> test = {1, 2, 3, 4};
    int k = 2;
    std::cout << diffK(test, k) << "\n";   
    return 0;
}