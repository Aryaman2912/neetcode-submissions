class Solution {
public:
    vector<int>freq1, freq2;
    bool matchFreqs(){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        freq1 = freq2 = vector<int>(26,0);
        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for(int i = s1.length(); i < s2.length(); i++){
            if(matchFreqs())
                return true;
            freq2[s2[i] - 'a']++;
            freq2[s2[i-s1.length()] - 'a']--;
        }
        if(matchFreqs())
            return true;
        return false;
    }
};