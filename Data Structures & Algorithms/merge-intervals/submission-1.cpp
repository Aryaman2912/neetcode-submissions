class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>x;
        vector<int>inte = intervals[0];
        for(int i = 1; i < n; i++){
            if(inte.back() >= intervals[i][0])
                inte[1] = max(inte[1], intervals[i][1]);
            else {
                x.push_back(inte);
                inte = intervals[i];
            }
        }
        x.push_back(inte);
        return x;    
    }
};
