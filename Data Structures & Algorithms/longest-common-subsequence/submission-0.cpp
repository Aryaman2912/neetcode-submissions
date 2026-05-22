class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>>dp(n, vector<int>(m,0));
        dp[0][0] = (text1[0] == text2[0]);
        for(int i = 1; i < n; i++){
            dp[i][0] = (dp[i-1][0] || (text1[i] == text2[0]));
        }
        for(int i = 1; i < m; i++){
            dp[0][i] = (dp[0][i-1] || (text2[i] == text1[0]));
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + (text1[i] == text2[j])));
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n-1][m-1];
    }
};


// dp[i][j] -> lcs s1[:i] and s2[:j]
// dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (s1[i]==s2[j]))