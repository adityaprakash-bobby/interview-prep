#include <iostream>
#include <vector>
#define fo(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)
#define MAX 1000

using namespace std;

int max_calorie(vector<vector<int>> calorie, int M, int N) {

    vector<vector<int>> boy1 (MAX, vector<int> (MAX, 0));
    vector<vector<int>> boy2 (MAX, vector<int> (MAX, 0));
    vector<vector<int>> girl1 (MAX, vector<int> (MAX, 0));
    vector<vector<int>> girl2 (MAX, vector<int> (MAX, 0));

    int max_cal = 0;

    // Calculate the calorie burnt by boy from top (1,1) to (i,j)
    fo(i, 1, M) {
        fo(j, 1, N) {
            boy1[i][j] = max(boy1[i-1][j], boy1[i][j-1]) + calorie[i-1][j-1]; 
        }
    }
    
    // Calculate the calorie burnt by boy from (i,j) and futher
    rfo(i, M, 1) {
        rfo(j, N, 1) {
            boy2[i][j] = max(boy2[i+1][j], boy2[i][j+1]) + calorie[i-1][j-1];
        }
    }

    // Calculate the calorie burnt by girl from bottom (M,1) to (i,j)
    rfo(i, M, 1) {
        fo(j, 1, N) {
            girl1[i][j] = max(girl1[i][j-1], girl1[i+1][j]) + calorie[i-1][j-1];
        }
    }

    // Calculate the calorie burnt by girl from (i,j) to futher
    fo(i, 1, M) {
        rfo(j, N, 1) {
            girl2[i][j] = max(girl2[i][j+1], girl2[i-1][j]) + calorie[i-1][j-1];
        }
    }

    // Now they can meet at point (i,j) where 2 <= i <= M-1 and 2 <= j <= N-1
    fo(i, 2, M-1) {
        fo(j, 2, N-1) {

            // There are two ways the can travel to cross each other only once
            // 1) boy (i-1,j) -> (i,j) -> (i+1,j) 
            //   girl (i,j-1) -> (i,j) -> (i,j+1)
            //                or
            // 2) boy (i,j-1) -> (i,j) -> (i,j+1) 
            //   girl (i+1,j) -> (i,j) -> (i-1,j)

            int way1 = boy1[i-1][j] + boy2[i+1][j] + girl1[i][j-1] + girl2[i][j+1];
            int way2 = boy1[i][j-1] + boy2[i][j+1] + girl1[i+1][j] + girl2[i-1][j];

            max_cal = max(max_cal, max(way1, way2));
        }
    }

    return max_cal;

}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{

    vector<vector<int>> calorie = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << max_calorie(calorie, calorie.size(), calorie[0].size()) << endl;

    return 0;
}