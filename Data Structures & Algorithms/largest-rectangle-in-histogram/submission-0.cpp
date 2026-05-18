class Solution {
public:
    int recurse(vector<int>& heights, int l, int r){
        if(l == r)
            return heights[l];
        int mid = (l + r) / 2;
        int maxl = recurse(heights, l, mid);
        int maxr = recurse(heights, mid + 1, r);
        int x = min(heights[mid], heights[mid + 1]);
        int i = mid, j = mid + 1;
        while(i >= l and heights[i] >= x)i--;
        while(j <= r and heights[j] >= x)j++;
        int t = x * (j - i - 1);
        return max(max(maxl, maxr), t);
    }
    int largestRectangleArea(vector<int>& heights) {
        return recurse(heights, 0, heights.size() - 1);
    }
};
