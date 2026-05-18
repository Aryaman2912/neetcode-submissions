class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            swap(nums1, nums2);
        }
        int n1 = nums1.size(), n2 = nums2.size(), l = 0, r = n1;
        int mid_total = (n1 + n2 + 1) / 2;
        while(l <= r){
            int mid = (l + r) / 2;
            int mid2 = mid_total - mid;
            int maxl1 = mid == 0 ? INT_MIN : nums1[mid-1];
            int minr1 = mid == n1 ? INT_MAX : nums1[mid];
            int maxl2 = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            int minr2 = mid2 == n2 ? INT_MAX : nums2[mid2];
            if(maxl1 <= minr2 and maxl2 <= minr1){
                if((n1 + n2) % 2) {
                    return max(maxl1, maxl2);
                } else {
                    return (1.0 * (max(maxl1, maxl2) + min(minr1, minr2))) / 2.0;
                }
            }
            if(maxl1 > minr2){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
    }
};