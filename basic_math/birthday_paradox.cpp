#include <iostream>
#include <cmath>

using namespace std;

/*
    Function to return the maxmimum number of people in the room to have 
    same bithdays given the probability
*/
int numPeopleRoom(double p) {

    if (p == 1) {
        return 367;
    }

    return ceil(sqrt(2*365*log(1/(1-p))));
}

/* Driver to test the above */
int main(int argc, char const *argv[])
{
    double probability = 1;
    cout << numPeopleRoom(probability) << "\n";

    return 0;
}