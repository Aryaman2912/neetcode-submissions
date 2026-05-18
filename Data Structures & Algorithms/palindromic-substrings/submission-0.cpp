class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n,0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            cnt++;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j] and (dp[i+1][j-1] or (i+1 > j-1))){
                    dp[i][j] = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
