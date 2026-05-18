class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost1 = 0, cost2 = 0;
        for(int i = 2; i <= cost.size(); i++){
            int minc = min(cost1 + cost[i-2], cost2 + cost[i-1]);
            cost1 = cost2;
            cost2 = minc;
        }
        return cost2;
    }
};