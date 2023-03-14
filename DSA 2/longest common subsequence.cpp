#include <iostream>
#include <cstring>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    
    int dp[n1 + 1][n2 + 1];
    
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[n1][n2];
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << longestCommonSubsequence(s1, s2) << endl; // Output: 3
    
    string s3 = "AGGTAB";
    string s4 = "GXTXAYB";
    cout << longestCommonSubsequence(s3, s4) << endl; // Output: 4
    
    return 0;
}
