#include <iostream>
#include <vector>

using namespace std;

/* print the vector (or) array */
void print_arr(vector<int> arr) {

    vector<int>::iterator it;

    for(it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }

}

/* Function to print the spiral */
vector<int> spiral_order(const vector<vector<int> > &A) {
    
    vector<int> res;
    
    int top = 0;
    int bottom = A.size() - 1;
    int left = 0;
    int right = A[0].size() - 1;
    int dir = 0;
    
    while(top<=bottom && left<=right) {
        
        if (dir == 0) {
            
            for (int i = left; i <= right; i++)
                res.push_back(A[top][i]);
            
            top++;
            
        }
        
        if (dir == 1) {
            
            for (int i = top; i <= bottom; i++)
                res.push_back(A[i][right]);
            
            right--;
            
        }
        
        if (dir == 2) {
            
            for (int i = right; i >= left; i--)
                res.push_back(A[bottom][i]);
            
            bottom--;
            
        }
        
        if (dir == 3) {
            
            for (int i = bottom; i >= top; i--)
                res.push_back(A[i][left]);
            
            left++;
            
        }
        
        dir = (dir + 1) % 4;

    }
    
    return res;
}

/* Driver for spiral */
int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> res = spiral_order(v);
    print_arr(res);

    return 0;
}