class Solution {
public:
    bool helper(int s, vector<int>& nums){
        int n = nums.size();
        if(s >= nums.size() - 1)
            return true;
        for(int i = s+1;i < n && i <= (s+nums[s]);i++){
            if(helper(i,nums))
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return helper(0,nums);
    }
};
