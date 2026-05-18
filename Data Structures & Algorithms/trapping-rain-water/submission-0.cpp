class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        while(!height[l])l++;
        while(!height[r])r--;
        int lmax = height[l], rmax = height[r];
        int trapped = 0;
        while(l < r){
            int x = min(height[l], height[r]);
            trapped += max(0,min(lmax, rmax) - x);
            // cout << l << " " << r << " " << min(lmax, rmax) - x << endl;
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax)
                l++;
            else
                r--; 
        }
        return trapped;
    }
};
