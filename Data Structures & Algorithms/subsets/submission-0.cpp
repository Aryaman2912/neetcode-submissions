class Solution {
public:
    vector<vector<int>>res;
    void recurse(vector<int>& nums, vector<int>& cur, int ind){
        if(ind == nums.size()){
            res.push_back(cur);
            return;
        }
        recurse(nums,cur,ind+1);
        cur.push_back(nums[ind]);
        recurse(nums,cur,ind+1);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        recurse(nums, cur, 0);
        return res;
    }
};