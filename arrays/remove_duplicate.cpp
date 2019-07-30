#include <iostream>
#include <vector>

using namespace std;

/*
    Function to return the duplicate element in less than O(n) time and O(1)
    space
 */
int returnDuplicate(vector<int> A) {

    vector<int> res (A.size(), 1);
    for (int i = 0; i < A.size(); i++) {
       
        if (res[A[i]] == 1) {
            res[A[i]] = 0;
        } else {
            return A[i];
        }

    }

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{

    vector<int> test = {3, 4, 1, 4, 1};
    cout << returnDuplicate(test) << endl;
    return 0;
}