#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* Check whether B is a subset of A*/
bool isSubset(vector<int> A, vector<int> B) {

    unordered_set<int> keys;

    keys.insert(A.begin(), A.end());

    for (int i = 0; i < B.size(); i++) {
        if (keys.find(B[i]) == keys.end()) {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{   
    vector<int> arr1 = {10, 5, 2, 23, 19};
    vector<int> arr2 = {19, 5, 3};

    cout << isSubset(arr1, arr2) << endl;

    return 0;
}