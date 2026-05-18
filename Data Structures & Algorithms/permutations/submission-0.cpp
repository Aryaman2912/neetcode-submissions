class Solution {
public:
    vector<vector<int>>res;
    vector<bool>visited;
    vector<int>cur;
    void recurse(vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                cur.push_back(nums[i]);
                recurse(nums);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(),false);
        recurse(nums);
        return res;
    }
};
