class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int max_area = 0;
        while(l < r){
            int area = (r - l) * min(heights[l], heights[r]);
            max_area = max(max_area, area);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};
