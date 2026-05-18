class Solution {
public:
    set<vector<int>>res;
    void recurse(vector<int>& candidates, multiset<int>& x, int target){
        if(target <= 0){
            if(target == 0)
                res.insert(vector(x.begin(), x.end()));
            return;
        }
        for(int i = 0; i < candidates.size(); i++){
            if(target - candidates[i] >= 0){
                x.insert(candidates[i]);
                recurse(candidates,x,target-candidates[i]);
                x.erase(x.find(candidates[i]));
            } else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        multiset<int>x;
        recurse(candidates, x, target);
        return vector(res.begin(), res.end());
    }
};