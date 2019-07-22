#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Function to return the lexicographically smaller wave array */
void waveArray(vector<int> &A) {

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 1; i += 2) {
        swap(A[i], A[i+1]);
    }

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 3, 4};
    waveArray(test);


    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    return 0;
}