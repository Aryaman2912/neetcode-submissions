class Solution {
public:
    vector<int>freq;
    int K;
    bool minReplacements(){
        int mf = 0, sumf = 0;
        for(int i = 0; i < freq.size(); i++){
            mf = max(mf, freq[i]);
            sumf += freq[i];
        }
        return ((sumf - mf) <= K);
    }

    int characterReplacement(string s, int k) {
        int n = s.length(), l = 0, r = 0;
        K = k;
        freq = vector<int>(26,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            freq[s[i] - 'A']++;
            while(!minReplacements()){
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
