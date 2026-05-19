class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n and (coins[i] <= amount); i++){
            dp[coins[i]] = 1;
        }
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n && (coins[j] <= i) ; j++){
                if(dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};