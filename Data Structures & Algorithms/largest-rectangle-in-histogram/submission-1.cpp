class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevs(n,0), nexts(n,0);
        stack<int>st;
        st.push(0);
        for(int i = 1; i < n; i++){
            int cnt = 0;
            while(!st.empty() and heights[st.top()] >= heights[i]){
                cnt += prevs[st.top()] + 1;
                st.pop();
            }
            prevs[i] = cnt;
            st.push(i);
        }
        while(!st.empty())st.pop();
        st.push(n-1);
        for(int i = n - 2; i >= 0; i--){
            int cnt = 0;
            while(!st.empty() and heights[st.top()] >= heights[i]){
                cnt += nexts[st.top()] + 1;
                st.pop();
            }
            nexts[i] = cnt;
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (prevs[i] + nexts[i] + 1));
        }
        return ans;
    }
};
