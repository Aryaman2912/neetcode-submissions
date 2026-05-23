class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        vector<vector<int>>dp(n,vector<int>(3,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        int res = max(dp[0][0], max(dp[0][1],dp[0][2]));
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            res = max(dp[i][0], max(dp[i][1], dp[i][2]));
        }
        return res;
    }
};
