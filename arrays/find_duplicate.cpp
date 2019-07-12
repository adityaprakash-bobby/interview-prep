#include <iostream>
#include <vector>
#include <map>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/*
    Function to find the duplicate items in the array in linear time and less
    than O(n) space complexity
*/
int findDuplicate(vector<int> A) {

    // Let's declare a map structure to keep track of the visited and unvisited
    // elements
    map<int, int> visited;

    // Here, we check if already present in the visited map, if present return
    // the key we are finding, else put it into the map and continue. If there
    // are no duplicate elements, return -1
    fo(i, 0, A.size() - 1) {

        if (visited.count(A[i]) == 1) {
            return A[i];
        } else {
            visited.insert({A[i], 1});
        }

    }

    return -1;

}

/* Driver function to test the above function */
int main(int argc, char const *argv[])
{

    vector<int> test = {3, 1, 4};
    cout << findDuplicate(test) << endl;
    return 0;
}