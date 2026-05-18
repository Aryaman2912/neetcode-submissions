class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        unordered_map<int,int>freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        for(auto it: freq){
            pq.push({it.second, it.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int>res;
        while(!pq.empty()){
            auto it = pq.top();
            res.push_back(it[1]);
            pq.pop();
        }
        return res;
    }
};
