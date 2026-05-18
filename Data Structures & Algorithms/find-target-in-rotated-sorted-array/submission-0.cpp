class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, pivot;
        if(nums[l] < nums[r])
            pivot = 0;
        else{
            while(l < r){
                int mid = (l + r) / 2;
                if(nums[mid] >= nums[0] and nums[mid] >= nums.back()){
                    l = mid + 1;
                } else if(nums[mid] <= nums[0] and nums[mid] <= nums.back()){
                    r = mid;
                }
            }
            pivot = r;
        }
        cout << pivot << endl;
        l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[(mid + pivot) % n] > target){
                r = mid - 1;
            } else if(nums[(mid + pivot) % n] < target){
                l = mid + 1;
            } else {
                return (mid + pivot) % n;
            }
        }
        return -1;

    }
};
