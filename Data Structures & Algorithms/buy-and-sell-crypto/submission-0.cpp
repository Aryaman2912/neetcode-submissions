class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = prices[0];
        int res = 0;
        for(int i = 1; i < n; i++){
            res = max(res, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        return res;
    }
};
