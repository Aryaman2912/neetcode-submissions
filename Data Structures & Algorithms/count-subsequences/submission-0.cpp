class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>>dp(n, vector<int>(m,0));
        if(s[0] == t[0])
            dp[0][0] = 1;
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0] + (s[i] == t[0]);
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] += dp[i-1][j];
                if(s[i] == t[j]){
                    dp[i][j] += dp[i-1][j-1];
                }
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
