#include <iostream>
#include <vector>
#include <climits>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

vector<int> maxFlipsArr(string A) {

    vector<int> res;
    int count_max = INT_MIN;
    int max_flip = 0;
    int start = 0, end = 0, left = 0, right = 0;

    for(int i = 0; i <= A.size() - 1; i++) {

        if (A[i] == '1') {
            max_flip -= 1;
        } else if (A[i] == '0') {
            max_flip += 1;
        }

        if (count_max < max_flip) {
            count_max = max_flip;
            start = left;
            end =  i;
        }
        
        else if (max_flip < 0) {
            max_flip = 0;
            left = i + 1;
        }

    }

    if (count_max > 0) {
        res.push_back(start + 1);
        res.push_back(end + 1);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    string test = "01100001";
    vector<int> res = maxFlipsArr(test);
    
    fo(i, 0, res.size() - 1) {
        cout << res[i] << " ";
    }    
    cout << endl;

    return 0;
}
