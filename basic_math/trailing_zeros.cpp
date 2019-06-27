#include <iostream>
using namespace std;

int trailing_0s (int A) {

    int count_5s = 0;
    
    for (int i = 0; i <= A; i += 5) {
        
        int j = i;
        while (j > 0) {
            
            if (j % 5 == 0) {
                count_5s++;
                j /= 5;
            } else {
                break;
            }

        }
        
    }
    
    return count_5s;

}

int main(int argc, char const *argv[])
{
    int number = 700;
    cout << trailing_0s(number);
    return 0;
}
