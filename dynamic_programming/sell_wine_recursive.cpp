#include <iostream>
#include <vector>

using namespace std;

int maximize_sale(vector<int> P, int beg, int end, int year) {

    if (beg > end) {
        return 0;
    }

    return max(
        maximize_sale(P, beg+1, end, year+1) + year*P[beg],
        maximize_sale(P, beg, end-1, year+1) + year*P[end] 
    );

}

/* Driver to test the above code */
int main(int argc, char const *argv[])
{
    vector<int> wines = {2, 3, 5, 1, 4};
    cout << maximize_sale(wines, 0, 4, 1) << endl;
    return 0;
}
