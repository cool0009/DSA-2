#include <iostream>
#include <string>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int i = m, j = n;
    string result = "";
    while(i>0 && j>0) {
        if(str1[i-1] == str2[j-1]) {
            result = str1[i-1] + result;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            result = str1[i-1] + result;
            i--;
        }
        else {
            result = str2[j-1] + result;
            j--;
        }
    }
    
    while(i>0) {
        result = str1[i-1] + result;
        i--;
    }
    while(j>0) {
        result = str2[j-1] + result;
        j--;
    }
    
    return result;
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    
    string result = shortestCommonSupersequence(str1, str2);
    cout << "The shortest string that has both " << str1 << " and " << str2 << " as subsequences is: " << result << endl;
    
    return 0;
}
