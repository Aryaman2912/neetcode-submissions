class Solution {
public:
    unordered_map<char,int>freq1, freq2;
    bool match_freqs(){
        for(auto c = 'a'; c <= 'z'; c++){
            if(freq1[c] < freq2[c])
                return false;
        }
        for(auto c = 'A'; c <= 'Z'; c++){
            if(freq1[c] < freq2[c])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        if(s.length() < t.length())
            return "";
        for(int i = 0; i < t.length(); i++){
            freq2[t[i]]++;
            freq1[s[i]]++;
        }
        int ans = INT_MAX, l = 0, r = t.length() - 1, minl;
        if(match_freqs()){
            l = 0, r = t.length() - 1;
            ans = r - l + 1;
            minl = 0;
        }
        while(l <= r and r < n){
            if(match_freqs()){
                if(r - l + 1 < ans){
                    ans = r - l + 1;
                    minl = l;
                }
                freq1[s[l]]--;
                l++;
            } else {
                r++;
                freq1[s[r]]++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(minl, ans);
    }
};
