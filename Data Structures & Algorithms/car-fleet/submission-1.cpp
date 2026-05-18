class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>>pairs;
        for(int i = 0; i < n; i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<float>st;
        st.push(1.0 * (target - pairs[0][0]) / (1.0 * pairs[0][1]));
        int i = 1;
        while(i < n){
            float time1 = st.top();
            float time2 = 1.0 * (target - pairs[i][0]) / (1.0 * pairs[i][1]);
            if(time2 > time1){
                st.push(time2);
            }
            i++;
        }
        return st.size();
    }
};
