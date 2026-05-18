class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int val1,val2;
        val1 = nums[0];
        val2 = max(nums[1],nums[0]);
        for(int i = 2; i < n; i++){
            int temp = max(val2, val1 + nums[i]);
            val1 = val2;
            val2 = temp;
        }
        return max(val1,val2);
    }
};