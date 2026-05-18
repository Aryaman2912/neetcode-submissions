class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 0, r = piles.back();
        while(l < r){
            int mid = (l + r) / 2;
            int hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += ceil((1.0 * piles[i]) / (1.0 * mid));
            }
            if(hours <= h){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r == 0 ? 1 : r;
    }
};
