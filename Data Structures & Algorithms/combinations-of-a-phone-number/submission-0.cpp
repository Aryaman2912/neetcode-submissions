class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>res;
    string cur;
    void rec(string digits, int ind){
        if(ind == digits.size()){
            res.push_back(cur);
            return;
        }
        for(auto c: mp[digits[ind]]){
            cur.push_back(c);
            rec(digits, ind + 1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(!n)
            return res;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        rec(digits, 0);
        return res;
    }
};