#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void sortString(string &S, int n, int m) {
    
    sort(S.begin() + n, S.begin() + m + 1, greater <char>());
    
}

int main() {

    int t;
    cin >> t;
    
    while (t--) {
 
        string str;
        int n, m;
 
        cin >> str >> n >> m;
        sortString(str, n, m);
 
        cout << str << endl;
    }

    return 0;    
}