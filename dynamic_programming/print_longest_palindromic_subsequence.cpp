#include <iostream>
#include <algorithm>

std::string longestCommonSubsequence(const std::string& A, const std::string& B) {
    
    int m = A.size();
    int n = B.size();

    int res[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                res[i][j] = 0;
            } else if (A[i-1] == B[j-1]) {
                res[i][j] = res[i-1][j-1] + 1;
            } else {
                res[i][j] = std::max(res[i-1][j], res[i][j-1]);
            }
        }
    }

    int idx = res[m][n];

    std::string lcs (idx+1, '\0');

    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            lcs[idx-1] = A[i-1];
            i--;
            j--;
            idx--;
        } else if (res[i-1][j] > res[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

std::string longestPalindromicSubsequence(const std::string& A) {
    std::string B = A;
    reverse(B.begin(), B.end());
    std::string res = longestCommonSubsequence(A, B);
    std::cout << res << std::endl;
    return res.substr(0, res.length() - 1);
}

int main(int argc, char const *argv[])
{
    std::string testString = "BBABCBCAB";
    
    std::cout << longestPalindromicSubsequence(testString) << "\n";

    return 0;

}