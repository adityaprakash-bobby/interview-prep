#include <iostream>
#include <vector>

int lengthPalindromicSubsequence(const std::string &A) {

    int N = A.length();
    int res[N][N];

    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }

    for (int str_len = 2; str_len <= N; str_len++) {
        for (int i = 0; i < N - str_len + 1; i++) {

            int j = i + str_len - 1;

            if (A[i] == A[j] && str_len == 2) {
                res[i][j] = 2;
            } else if (A[i] == A[j]) {
                res[i][j] = res[i+1][j-1] + 2;
            } else {
                res[i][j] = std::max(res[i][j-1], res[i+1][j]);
            }
        }
    }

    return res[0][N-1];
}

int main(int argc, char const *argv[])
{
    std::string testString = "BBABCBCAB";
    
    std::cout << lengthPalindromicSubsequence(testString) << "\n";

    return 0;
}