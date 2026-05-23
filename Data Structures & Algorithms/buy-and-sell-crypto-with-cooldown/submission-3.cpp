class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        vector<int>dp(n,0);
        dp[1] = max(dp[0], prices[1] - prices[0]);
        int res = max(dp[0], dp[1]);
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1];
            dp[i] = max(dp[i], max(prices[i] - prices[1], prices[i] - prices[0]));
            res = max(res, dp[i]);
            for(int j = 2; j <= i; j++){
                dp[i] = max(dp[i], prices[i] - prices[j] + dp[j-2]);
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
