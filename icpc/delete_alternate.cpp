#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* Function to delete every person 2 places infront the other in a circle */
vector<int> remainingPeople(int A) {

    vector<int> res(A);
    iota(res.begin(), res.end(), 1);

    for (int i = 0; i < res.size(); ) {

        int erase_ix = (i+2)%res.size();
        int erase_num = res[erase_ix];
        int flag = 0;

        if (res[i] != res[erase_ix]) {
            // do the normal procedure
            if (res[i] < erase_num) {
                flag = 1;
            } else {
                flag = 0;
            }

            res.erase(res.begin() + erase_ix);

            i = (i+flag)%res.size();

        } else {
            // quit the process
            break;
        }

    }

    return res;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    int test = 4;
    vector<int> res = remainingPeople(test);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}