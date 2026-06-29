class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int>freq;
        int min_val = hand[0], max_val = hand[0];
        for(int i = 0; i < n; i++){
            freq[hand[i]]++;
            min_val = min(min_val, hand[i]);
            max_val = max(max_val, hand[i]);
        }
        int cur = min_val;
        while(cur <= max_val){
            for(int i = 0; i < groupSize; i++){
                if(freq.find(cur+i) == freq.end() or !freq[cur+i]){
                    // cout << cur+i << endl;
                    return false;
                }
                // cout << cur + i << " ";
                freq[cur+i]--;
                // cur++;
            }
            cout << endl;
            while(cur <= max_val and (freq.find(cur) == freq.end() or !freq[cur])){
                cur++;
            }
            // cout << "new cur: " << cur << endl;
        }
        return true;
    }
};