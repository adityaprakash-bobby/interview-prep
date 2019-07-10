#include <iostream>
#include <vector>

using namespace std;

/*
    Function to return unique element from array where every other element
    appears thrice
*/
int uniqueElement(vector<int> A) {

    int appear_once = 0;
    int appear_twice = 0;
    int not_thrice;

    for (int i = 0; i < A.size(); i++) {

        appear_twice |= appear_once & A[i];
        appear_once ^= A[i];

        not_thrice = ~(appear_twice & appear_once);
        appear_once &= not_thrice;
        appear_twice &= not_thrice;

    }

    return appear_once;

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 2, 3, 3, 2, 3};
    cout << uniqueElement(test) << endl;   
    return 0;
}