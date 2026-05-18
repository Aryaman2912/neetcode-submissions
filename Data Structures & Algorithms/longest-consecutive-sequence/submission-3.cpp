class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            int next = nums[i] + 1, prev = nums[i] - 1;
            while(mp.find(next) != mp.end() and mp[next] != 0){mp[next]=0;next++;}
            while(mp.find(prev) != mp.end() and mp[prev] != 0){mp[prev]=0;prev--;}
            res = max(res,next-prev-1);
        }
        return res;
    }
};

