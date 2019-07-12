#include <iostream>
#include <vector>

using namespace std;

/* Function that returns primes within number N */
vector<int> listPrimeSieve(int N) {

    int *list = new int[N+1];
    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        
        if (list[i] == 0) {
        
            list[i] = i;
            primes.push_back(i);
        
        }

        for (int j = 0; j<(int)primes.size() && \
                    primes[j]<=list[i] && i*primes[j]<=N; j++) {
            list[i*primes[j]] = primes[j];
        }

    }

    return primes;
}

/* Driver function to test the above function and print 0%100 indexed prime */
int main(int argc, char const *argv[])
{
    int N = 100000000;
    vector<int> primes_list = listPrimeSieve(N);
    int ctr = 0;
    for (auto it = primes_list.begin(); it != primes_list.end(); it++) {
        if (ctr%100 == 0) {
            cout << *it << " ";
        }
        ctr++;
    }
    cout << "\n";

    return 0;
}