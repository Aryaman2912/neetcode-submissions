class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n == 0 or m == 0){
            return (n + m);
        }
        vector<vector<int>>dp(n,vector<int>(m,0));
        bool isPresent = (word1[0] == word2[0]);
        dp[0][0] = (word1[0] != word2[0]);
        for(int i = 1; i < n; i++){
            isPresent = (isPresent || (word1[i] == word2[0]));
            dp[i][0] = i + !isPresent;
        }
        isPresent = (word1[0] == word2[0]);
        for(int i = 1; i < m; i++){
            isPresent = (isPresent || (word1[0] == word2[i]));
            dp[0][i] = i + !isPresent;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = min(dp[i][j-1] + 1, min(dp[i-1][j] + 1, dp[i-1][j-1] + (word1[i] != word2[j])));
            }
        }
        return dp[n-1][m-1];
    }
};
