class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            auto x = lower_bound(lis.begin(), lis.end(), nums[i]);
            if(x == lis.end()){
                lis.push_back(nums[i]);
                continue;
            }
            lis[x - lis.begin()] = nums[i];
        }
        return lis.size();
    }
};
