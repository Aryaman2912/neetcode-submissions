class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l < r){
            int x = numbers[l] + numbers[r];
            if(x > target)
                r--;
            else if (x < target)
                l++;
            else
                return {l+1,r+1};
        }
        return {l,r};
    }
};
