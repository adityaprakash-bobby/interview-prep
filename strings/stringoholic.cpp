/* Load required header files */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/* Pre-processors and typedef constants */
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define MOD 1000000007

typedef unsigned long long int ll;

/* Function to find the common length where the strings rotated remains the same */
int stringoholic(vector<string> A) {

    int l = 1,len=A.size(),h;
    vector<int> v(len);
    for(int k=0;k<len;k++){
        
        int n = A[k].length(); 
    
        if (n<=1) { 
            v[k] = 1;
        } else {

            ll i = 1, j = 1, changes = 0;
            
            while(1) {
            
                changes = (i*(i+1))/2; 
                
                if(changes%n==0){
                    v[k]=i;
                    break;
                }
                
                i++;
            
            }
     
        } 
     
    }

    ll _lcm = 1;
    
    for(int i=0;i<len;i++){
        
        for(int j=i+1;j<len && v[i]!=1 ;j++){
            v[j] = v[j]/__gcd(v[j],v[i]);
        }
        
        _lcm = 1ll * (_lcm%MOD * (v[i])%MOD) % MOD;
    
    }

    return _lcm%MOD;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{   
    IOS;
    vector<string> test = {"bbababbbaabbaaabbbab", "baabaaaabbbbaabbbaaabbabbbabbaaaaaaabaaababbaa", "aababaaaabbbabbabbabaabbabababaabbabaabababbbabababaabbaabaaaa", "aaabaaaabbbaababaaaaabbbabbabbbbbbababbbaaaababaaaaababbbaaaa", "abaababaabbaaaabaabbabbaaaaaaabaaabbaabaaaaababbabababbabbba", "aaaabbbaababaaaabbbaaaabbbbaabaababbbababbbbbbaaabb", "b", "aaabaaabbbbaababbbaabbbbabababaabbbbbbaaaaab", "aaaabababaaaababaaabbbaaabbababaababbbaabaababaababbbbbbaabaaaabbaaaba", "abbbbabbbbaaabaaaababaaabaaabbabababbbabaababbabaabbabbbbbbaaababbbbabaabbbbbbabbaabbbbbaab", "abbaabbbabbaaabbababbabbbaaaabbbaabbbaaabbababbaabbaaabbabbbaaabbbaabaaababbbabaabaabbba", "bbabbbaabbbbbbbaaabba", "bbbbaaaaabbbbaabaaabbaaaabbbabbbaaaa", "abbaaabbbabbbbabbbbaaa", "bbbbabbbaaaabbbaabbbaabbaaaaabbbaaaaaabaaaabbbbbababbbababaaabaabab", "aabbababaaabbaaaaaaabaabbaaabbabbbaabbbbbaaaaaaabaaaababbaaabaaabaaabaaaaaaabbbabbaaaabaababbaabbaba", "bbaab", "baababbaaabaabaaababaabababbababbaabaabaabaaaaaabaabbbaabbbaaabaaaba", "baaaaaabbaabaaabaab", "abaaaaaabbaabaaabababbbbbabbaababbabbbaaaabbbbbaaaabababbbbabaaabbaaaaaaabbbbbbbbbabbabaaaabababaaba", "baabbaaabbabbbabaababbaabbabaabaabbbbbabaaabbaaaaaabbbbaabbbbabbbabbbbabbaaaaaaaabababbababaa", "aaabbbababbabbbab", "bbbbbababbabbabababbbaaaaa", "babbbaaababbbaabaaaaabbbababaaabababaabbbababbbbbabbbabbabaabbbbaaaaabab", "baaabbbbabab", "abbab", "babaababaaabbaababbbaaa", "aaababbabaaababbbbaaaaaaabbabbbbbbaaababbabaaabbabaa", "aaabbaabbbaabaaaabbabbbbaabbabbabbbbbbaaaaabbabba", "abbbabbab", "baabaaabbaaaaabbbbbbbbabaaababbaaab", "abbbbbbbabbbaaabbaabababaabaaaaabababbbbaaaaa", "bbaaabbbabbbabbabaaaaabbbbaabaababbaaabababbbaaaaabaaabaababaaa", "bbabbabbaaaaaaaabbabaababbbbaabbbabbaaaabaabbbaaaabaabaaaabaababbbabbababaaabaabababaabbaab", "bbaaaababbaabaaaaabbbbaaabbababbabbabbaaababbabaaabaabaaababbbabaaaab", "abbbabbbbabaabbabbbaaabbaabaaaa", "babbbbaabbabbbbaaaaaaabaaaaaaba", "baaabaaaaabbbabbaabaabbabbaaaabbaabbabbababaabbabbbbaabbbbbabbbabbbbabaabbaaaaab", "babbbabaababaaabbbaabaabaabaabbababbbabbbbaababbbbbbbb", "abbaaaaaaabbbaaabaabbabaaaababbabaabbab", "baaaaabaabbaaaaababbaabbababababbababaabab", "aaaababaabbbbabbaabbaababbaabbabbabaaaabbbabaaaaabaabbaa", "abaabbbbbabbaababaabaabba", "bbababaabbbaaaaaababbbbbabbaaaabbabbbbbabbbbbbbbaaabbbaaaaabaaababbabaaabbbbbbabbbbaa", "abbaabaabbaabbabbabababbbaaabbababaabaaabaaabaaaabbbbababbbaabbaabababbbbbabaababaaabbaa", "bababbbbaabbaaababbababbababaabbaaaaabbababbabbbbabaa", "baaabaababbabbbabaaaaaabbbbbbaaaaaaabbbbaabbaabbabaababbbbaabaababbbaaaabbbbbaaabaaaaabbbbba", "ababbbbbabababbaabbabbbbbaaaaaaa", "abbbaabbbbbaababababaaaaababbabbbaabaaabb", "abaaaabaabaaabbaaabbbabaabaabbabaababbababbaabbababbaababbbaabbabb", "aaababbbbaabbaaaaabbaaaaabaaababbbababaababbaabbabaab", "babbababababaaabaab", "baaababbbbbababbbbaaaababbbbbbbabbbaa", "bbbabaaaabbabbbabaabbbabababbababbaabaabbbababbabbbabbbbaaababbaabaabbbaabbba", "bbaaabbbabbaaaabaaaaabbababbbaaabaababbaaabaabbabbbaaaabababbabbbbababbaaaaabbbbaabaab", "baaaabababbbabaabbbbaaabbaabbbbaaaaababbaaaabaaabbaaaabbbaaabaabaabbbaabbabaabbabbabbbaabaabaaa", "babaabbbbaaabbaaaabbb", "abaaaa", "abaaaabababbababbbbbabbabaabaaaababaaaabababbbaaaaaabbaababbbabaaaabaa", "bababaabaabababbbbbaababbabababaaaabaaaabaaaabaabbabaaabbaaaabaababbabbbbba", "baaababbbaaaaaa", "baaaabbaaaaaaaabaabbaaabaababbaababbbaaabaabaaaaabbabbaabbaabbbabaabaabbabaabaa", "bbbbabbbbbaaabaababbaababbaaaa", "bbaababbbbbbbabbbaaaaabbbbbbba", "abbbbbaaabbbbbaaaababbaabbbaabbabababaabbbaaaababaaabaaabbbbbaaaababbaabbabbaab", "abbaababbbbabbabaaaaaabbaaabbbabaababaaabbabaaaaabaabbbaabbb", "babbabbabbbaaaaabbbabbbbbbbaaabaaababaabaabaaaabbbbabbbaaaababbbbabbbaababbabbaabbbaaaa", "baabababbaaaaabaaaabaaababbabbbabbabaabaabaaaaaaabbabbbbaaaabbab", "aabbbbbbaabaabababbaaaabaaaabbbbaaabaaaaabaaaaabbbbabbbaab", "bbbabbbabbbbbabbbabababbaaa", "aaabbbaaabaaabbbababbabaaaaaaaabaaabbab", "baabbbabababbbabb", "aaaabbbbaaaaabaabba", "baababbabaabaabb", "ababbabaaabbabaabaabbaabababababaaababaabbabaaaaaabbbbbbabaaabbbbbaa", "aaaaaaabaababbbaababbbbaaa", "aba", "babbbbaababaaabaaabbaabaabaaaababbbaabaaabaa", "baaabaabbaaababbababaabaabaabaabaabaabbbbbaaabaaaababaabaabbabababbaaaaaaaa", "baabbbbababbabbbabaabbbbbbbbbabaabbbaabaabbbaaaaaabbb", "aabaaaabaabbabbbbaabbabbbbbaaaababbabbabbbababbabbbaaabbaabaabbbaabbbbabaaabbbb", "babbabaabb"};
    cout << stringoholic(test) << endl;
    return 0;
}