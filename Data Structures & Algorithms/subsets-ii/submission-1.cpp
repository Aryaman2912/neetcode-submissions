class Solution {
public:
    set<vector<int>>res;
    void recurse(vector<int>& nums, vector<int>& cur, int ind){
        if(ind == nums.size()){
            sort(cur.begin(),cur.end());
            res.insert(cur);
            return;
        }
        recurse(nums,cur,ind+1);
        cur.push_back(nums[ind]);
        recurse(nums,cur,ind+1);
        cur.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>cur;
        recurse(nums, cur, 0);
        return vector(res.begin(),res.end());
    }
};