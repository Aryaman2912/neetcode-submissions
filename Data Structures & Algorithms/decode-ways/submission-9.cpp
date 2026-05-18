class Solution {
public:
    int stoi(string s){
        return ((s[1]-'0') + (s[0]-'0') * 10);
    }
    bool isValid1(char c){
        return c != '0';
    }
    bool isValid2(int x, char c1, char c2){
        // cout << "isvalid2" << " " << x << endl;
        if(x == 0 or x > 26 or x < 10)
            return false;
        return true;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,0);
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        if(n == 1)
            return 1;
        int x = stoi(string(1,s[0]) + string(1,s[1]));
        cout << x << endl;
        if(isValid1(s[1]))
            dp[1] = dp[0];
        if(isValid2(x, s[1], s[0]))
            dp[1]++;
        if(dp[1] == 0)
            return 0;
        for(int i = 2; i < n; i++){
            int x = stoi(string(1,s[i-1]) + string(1,s[i]));
            if(isValid1(s[i]))
                dp[i] = dp[i-1];
            if(isValid2(x, s[i], s[i-1]))
                dp[i] += dp[i-2];
            // cout << x << endl;
            if(dp[i] == 0)
                return 0;
        }
        for(int i = 0; i < n; i++){
            cout << dp[i] << " ";
        }
        return dp.back();
    }
};
