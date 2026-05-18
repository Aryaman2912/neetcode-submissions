class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i = 0; i < n;){
            int l = i + 1, r = n - 1, a = nums[i];
            while(l < r){
                int b = nums[l], c = nums[r];
                int sum = a + b + c;
                if(sum == 0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(nums[l] == b)l++;
                    while(nums[r] == c)r--;
                    continue;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
                
            }
            while(nums[i] == a)i++;
        }
        return res;
    }
};