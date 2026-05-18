class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int start = nums[0], cur_len = 0, max_len = 0;
        for(int i = 0; i < nums.size(); i++){
            // cout << i << " " << nums[i] << " " << start << " " <<  cur_len << endl;
            if(nums[i] == start){
                while(i < n and nums[i] == start)i++;
                i--;
                start++;
                cur_len++;
            } else {
                max_len = max(max_len, cur_len);
                start = nums[i] + 1;
                cur_len = 1;
            }
        }
        cout << cur_len << endl;
        max_len = max(max_len, cur_len);
        return max_len;
    }
};

// -1 -1 0 1 3 4 5 6 7 8 9