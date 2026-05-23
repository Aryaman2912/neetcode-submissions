class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2)
            return false;
        sum /= 2;
        vector<bool>dp(sum+1,false);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = sum; j >= nums[i]; j--){
                if((j - nums[i] >= 0) and (dp[j-nums[i]])){
                    dp[j] = true;
                }
            }
        }
        return dp[sum];
    }
};
