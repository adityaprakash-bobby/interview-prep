#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Pre-processors and typedef constants */
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)

/* Function to find the longest prefix or suffix array */
vector<int> prefix_func(string str) {

    // Write your code logic in this region
    int length = str.size();
    vector<int> pf (length);

    pf[0] = 0;

    for (int i = 1; i < length; i++) {

        int j = pf[i-1];

        while (j > 0 && str[j] != str[i]) {
            j = pf[j-1];
        }

        if (str[i] == str[j]) {
            j++;
        }

        pf[i] = j;

    }

    return pf;
}

/* Function to find the occurrences of pattern in text and store their indices */
vector<int> occurencesText(string text, string pattern) {

    vector<int> end_pts;
    int i = 0, j = 0;
    vector<int> long_prefix = prefix_func(pattern);


    for (; i < text.size();) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        } 

        if (j == long_prefix.size()) {
        
            end_pts.push_back(i-j);
            j = long_prefix[j - 1];
        
        } else if (i < text.size() && pattern[j] != text[i]) { 
            
            if (j != 0) { 
                j = long_prefix[j - 1];
            } else {
                i = i + 1;
            }

        } 
    }

    return end_pts;
}

/* Driver function to test the above code */
int main(int argc, char const *argv[])
{   
    IOS;
    /* Initialize test variables and call your code function here */
    string A = "AABAABCAA";
    string B = "AA";

    vector<int> v = occurencesText(A, B);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}