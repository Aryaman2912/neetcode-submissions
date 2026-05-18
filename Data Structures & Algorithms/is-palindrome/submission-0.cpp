class Solution {
public:
    string process_string(string s){
        string res;
        for(char c: s){
            if((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
                res.push_back(c);
            else if (c >= 'A' and c <= 'Z')
                res.push_back('a' + (c - 'A'));
        }
        return res;
    }
    bool isPalindrome(string s) {
        s = process_string(s);
        int n = s.length();
        for(int i = 0 ; i < n; i++){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
};
