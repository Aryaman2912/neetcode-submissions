class Solution {
public:
    int ans = 0;
    void recurse(vector<int>& nums, int i, int target){
        if(target == 0 and i == nums.size()){
            ans++;
        }
        if(i == nums.size())
            return;
        recurse(nums,i+1,target-nums[i]);
        recurse(nums,i+1,target+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        recurse(nums,0,target);
        return ans;
    }
};
