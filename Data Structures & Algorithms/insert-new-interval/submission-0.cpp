class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n = intervals.size();
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        int m = newInterval.size();
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
    }
};
