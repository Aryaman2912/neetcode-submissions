class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, ans = 0, sumg = 0, sumc = 0;
        for(int i = 0; i < n; i++){
            sumg += gas[i];
            sumc += cost[i];
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                ans = (i + 1) % n;
            }
        }
        if(sumg < sumc)
            return -1;
        return ans;
    }
};
