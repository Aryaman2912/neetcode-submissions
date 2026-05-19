class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0], y = nums[0];
        int ans = x;
        for(int i = 1; i < n; i++){
            int t1 = min(nums[i], min(y * nums[i], x * nums[i]));
            int t2 = max(nums[i], max(y * nums[i], x * nums[i]));
            x = t1;
            y = t2; 
            ans = max(ans, y);
        }
        return ans;
    }
};
