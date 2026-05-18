class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>pos;
        int start = 0, cur = 0, n = s.length(), maxlen = 0;
        while(cur < n){
            if(pos.find(s[cur]) == pos.end() or pos[s[cur]] == -1){
                pos[s[cur]] = cur;
                cur++;
                continue;
            }
            maxlen = max(maxlen, cur - start);
            while(start <= pos[s[cur]]){
                pos[s[start]] = -1;
                start++;
            }
            pos[s[cur]] = cur;
            cur++;
        }
        maxlen = max(maxlen, cur - start);
        return maxlen;
    }
};
