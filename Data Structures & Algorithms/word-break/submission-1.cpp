class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(), m = wordDict.size();
        vector<bool>dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t1 = wordDict[j].length() - 1;
                int t2 = i;
                if((i-t1<0) or !dp[i-t1])
                    continue;
                while(t2 >= 0 and t1 >= 0){
                    if(wordDict[j][t1] == s[t2]){
                        t1--;
                        t2--;
                    } else {
                        break;
                    }
                }
                if(t1 == -1) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
