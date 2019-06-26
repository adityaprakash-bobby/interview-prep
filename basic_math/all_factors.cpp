#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* Function to find all factors of a number */
vector<int> allFactors(int A) {
    
    set<int> ret;
    vector<int> factors;
    
    for (int i = 1; i*i <= A; i++) {
        if (A%i == 0) {
            ret.insert(i);
            
            if (A/i != i) {
                ret.insert(A/i);
            }
        }
    }
    
    factors.assign(ret.begin(), ret.end());
    return factors;
    
}

/* Driver to find all factors of a number */
int main(int argc, char const *argv[])
{
    int number = 12;
    vector<int> factors = allFactors(12);
    
    for (auto i = factors.begin(); i != factors.end(); i++) {
        cout << *i << " "; 
    }
    cout << "\n";

    return 0;
}
