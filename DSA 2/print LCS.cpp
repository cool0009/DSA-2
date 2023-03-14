#include <iostream>
#include <cstring>
using namespace std;

void printLCS(char* s1, char* s2, int len1, int len2, int** dp) {
    if (len1 == 0 || len2 == 0) {
        return;
    }
    if (s1[len1 - 1] == s2[len2 - 1]) {
        printLCS(s1, s2, len1 - 1, len2 - 1, dp);
        cout << s1[len1 - 1];
    }
    else if (dp[len1 - 1][len2] > dp[len1][len2 - 1]) {
        printLCS(s1, s2, len1 - 1, len2, dp);
    }
    else {
        printLCS(s1, s2, len1, len2 - 1, dp);
    }
}

int longestCommonSubsequence(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int** dp = new int*[len1 + 1];
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printLCS(s1, s2, len1, len2, dp);

    int result = dp[len1][len2];

    for (int i = 0; i <= len1; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    cout << "LCS length: " << longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
