class Solution {
public:
    vector<vector<string>>res;
    vector<string>pals;
    bool isPal(string &s){
        int n = s.length();
        int l = 0, r = n - 1;
        while(l <= r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void recurse(string& s, int ind){
        if(ind == s.size()){
            res.push_back(pals);
            return;
        }
        string temp = "";
        for(int i = ind; i < s.length(); i++){
            temp.push_back(s[i]);
            if(isPal(temp)){
                pals.push_back(temp);
                recurse(s, i + 1);
                pals.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>pals;
        recurse(s, 0);
        return res;
    }
};