class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if(nums[l] < nums[r])
            return nums[l];
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] >= nums[0] and nums[mid] >= nums.back()){
                l = mid + 1;
            } else if(nums[mid] <= nums[0] and nums[mid] <= nums.back()){
                r = mid;
            }
        }
        return nums[r];
    }
};
