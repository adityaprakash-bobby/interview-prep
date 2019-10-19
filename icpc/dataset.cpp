/* Load required header files */
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

/* Pre-processors and typedef constants */
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define MOD 1000000007

typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

int countMax(map<pair<string, bool>, int> A) {

    int count = 0;

    for (auto it = A.begin(); it != A.end(); it++) {
        
        bool temp;
        
        if (it->first.second == 1) {
            temp = 0;
        } else {
            temp = 1;
        }
        
        if (A.find(make_pair(it->first.first, temp)) != A.end()) {
            count += max(it->second, A[make_pair(it->first.first, temp)]);
            // cout << it->first.first << " has duplicate" << endl;
            it++;
        } else {
            // cout << it->first.first << " has no duplicate" << endl;
            count += it->second;
        }

    }

    return count;
}

/* Main function */
int main(int argc, char const *argv[])
{   
    IOS;
    /* Initialize test variables and call your code function here */

    int t;
    cin >> t;

    while (t--) {

        string str;
        int ip;
        bool bol;

        cin >> ip;

        map<pair<string, bool>, int> test;

        for (int i = 0; i < ip; i++) {
            cin >> str >> bol;

            if (test.count(make_pair(str, bol)) > 0) {
                test[make_pair(str, bol)] += 1;
            } else {
                test.insert(make_pair(make_pair(str, bol), 1));
            }

        }

        // for (auto it = test.begin(); it != test.end(); it++) {
        //     cout << it->first.first << it->first.second << " "  << it->second << endl;
        // }

        cout <<countMax(test) << endl;
    }

    return 0;
}