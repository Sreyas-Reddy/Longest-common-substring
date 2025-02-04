#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubstring(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int maxLength = 0;
    int endIndex = 0;    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    string result = str1.substr(endIndex - maxLength, maxLength);

    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}

int main() {
    string str1, str2;
    
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string lcs = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << lcs << endl;

    return 0;
}