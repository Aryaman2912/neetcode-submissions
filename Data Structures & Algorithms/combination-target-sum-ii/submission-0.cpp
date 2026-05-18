class Solution {
public:
    set<vector<int>>res;
    void recurse(vector<int>& candidates, vector<int>& cur, int ind, int target){
        if(target <= 0){
            if(target == 0)
                res.insert(cur);
            return;
        }
        if(ind == candidates.size() or candidates[ind] > target)
            return;
        recurse(candidates,cur,ind+1,target);
        cur.push_back(candidates[ind]);
        recurse(candidates,cur,ind+1,target-candidates[ind]);
        cur.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>cur;
        recurse(candidates,cur,0,target);
        return vector(res.begin(), res.end());

    }
};