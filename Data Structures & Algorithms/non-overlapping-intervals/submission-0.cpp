class Solution {
public:
bool customComparison(vector<int> a, vector<int> b)
{
    return a[1] <= b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
            return a[1] <= b[1];
        });
        int ans = 0, last = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < intervals[last][1]){
                ans++;
                continue;
            }
            last = i;
        }
        return ans;

    }
};
