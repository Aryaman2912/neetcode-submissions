class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int>freq;
        int min_val = hand[0], max_val = hand[0];
        set<int>s;
        for(int i = 0; i < n; i++){
            freq[hand[i]]++;
            min_val = min(min_val, hand[i]);
            max_val = max(max_val, hand[i]);
            s.insert(hand[i]);
        }
        int cur = min_val;
        auto it = s.begin();
        while(it != s.end()){
            for(int i = 0; i < groupSize; i++){
                if(freq.find(cur+i) == freq.end() or !freq[cur+i]){
                    return false;
                }
                freq[cur+i]--;
            }
            while(it != s.end() and (freq[*it] == 0)){
                it++;
            }
            cur = *it;
        }
        return true;
    }
};