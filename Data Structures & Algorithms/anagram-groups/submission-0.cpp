class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>groups;
        for(int i = 0; i < strs.size(); i++){
            string x = strs[i];
            sort(x.begin(), x.end());
            groups[x].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto x: groups){
            res.push_back(x.second);
        }
        return res;
    }
};
