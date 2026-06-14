class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), r = 0;
        for(int i = 0; i < n && i <= r; i++){
            r = max(r, i + nums[i]);
        }
        return r >= n-1;
    }
};
