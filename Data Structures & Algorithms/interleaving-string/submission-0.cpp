class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        if(n + m != l)
            return false;
        if(n == 0 and m == 0 and l == 0)
            return true;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int i = 1;
        while(i <= n and i <= l and s1[i-1] == s3[i-1]){
            dp[i][0] = 1;
            i++;
        }
        i = 1;
        while(i <= m and i <= l and s2[i-1] == s3[i-1]){
            dp[0][i] = 1;
            i++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // cout << i << " " << j << " " << dp[i-1][j] << " " << dp[i][j-1] << endl;
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1]) ||
                            (dp[i][j-1] && (s2[j-1] == s3[i+j-1])));
            }
        }
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};
