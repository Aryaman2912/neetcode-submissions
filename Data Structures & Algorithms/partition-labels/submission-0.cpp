class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, vector<int>>mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i,i};
            }
            mp[s[i]][0] = min(mp[s[i]][0], i);
            mp[s[i]][1] = max(mp[s[i]][1], i);
        }
        vector<int>res;
        int ind = 0, end = 0, start = 0;
        for(int i = 0; i < n; i++){
            end = max(end, mp[s[i]][1]);
            if(i == end){
                res.push_back(end - start + 1);
                start = i + 1;
                end = start;
                continue;
            }
        }
        return res;
    }
};
