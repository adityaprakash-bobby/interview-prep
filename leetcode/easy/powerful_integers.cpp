#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        // use hashmap to store the already seen sums, values of x_pow/y_pow that
        // have been used already
        unordered_map<int, int> stored_already, x_pow_calced, y_pow_calced;
        
        int sum = 0, i = 0, j = 0;
        int x_pow = 1, y_pow = 1;

        while (true) {
            
            x_pow = pow(x, i);
            
            if (x_pow <= bound && x_pow_calced.find(x_pow) == x_pow_calced.end()) {
                
                x_pow_calced.emplace(x_pow, 1);
                
                while(y_pow_calced.find(y_pow) == y_pow_calced.end()) {
                    y_pow_calced.emplace(y_pow, 1);
                    
                    sum = x_pow + y_pow;

                    if (sum <= bound) {

                        if (stored_already.find(sum) == stored_already.end()) {
                            res.push_back(sum);                            
                            stored_already.emplace(sum, 1);
                        }

                        j++;
                        y_pow = pow(y, j);
                    
                    } else {
                        break;
                    }
                }

                i++;
                j = 0;
                y_pow = 1;
                y_pow_calced.clear();

            } else {
                break;
            }
        }
        return res;
    }
};