#include <iostream>
#include <vector>

using namespace std;

/* 
    Function to find anti-diagonals. For given 2-D array,  
    {a b c}
    {d e f}
    {g h i}
    the anti diagonal representation will be as follows:
    {a}
    {b d}
    {c e g}
    {f h}
    {i} 
*/
vector<vector<int>> anti_diag(vector<vector<int>> &arr) {

    vector<vector<int>> res;

    if (arr.size() == 0) {
        return res;
    }

    for(auto it = 0; it <= 2 * (arr.size() - 1); it++) {

        vector<int> temp;

        for (auto i = 0; i <= it; i++) {
            int j = it - i;
            if(i >= arr.size() || j >= arr.size())
                continue;

            temp.push_back(arr[i][j]);

        }

        res.push_back(temp);
        temp.clear();   
    }

    return res;

}

/* Driver to test the function */
int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> res = anti_diag(arr);

    for (auto i = 0; i < res.size(); i++) {
        for (auto j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    } 
    
    return 0;
}
