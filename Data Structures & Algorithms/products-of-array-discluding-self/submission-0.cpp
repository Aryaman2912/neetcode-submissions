class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prod1(n,1), prod2(n,1);
        vector<int>res(n);
        for(int i = 1; i < n; i++){
            prod1[i] = prod1[i-1] * nums[i-1];
            prod2[n-1-i] = prod2[n-i] * nums[n-i];
        }
        for(int i = 0; i < n; i++){
            res[i] = prod1[i] * prod2[i];
        }
        return res;
    }
};