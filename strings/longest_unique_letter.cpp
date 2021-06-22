#include <bits/stdc++.h>

using namespace std;

int longestUniqueChar(string s)
{
    int maxLen = 0;
    int tempLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // add to the tempLen
        tempLen++;
        // check if the next is different that the current or is end
        // likewise update the maxLen
        if (i + 1 == s.size() || s[i] != s[i + 1])
        {
            maxLen = max(tempLen, maxLen);
            tempLen = 0;
        }
    }

    return maxLen;
}

int main()
{
    string str = "--1221--2-12123";
    cout << longestUniqueChar(str) << endl;
}