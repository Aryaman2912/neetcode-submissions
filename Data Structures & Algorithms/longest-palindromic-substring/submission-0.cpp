class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        int maxlen = 1, start = 0, end = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j] and (dp[i+1][j-1] or (i+1 > j-1))){
                    dp[i][j] = 1;
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
