class Compare {
public:
    bool operator()(pair<char,int>p1,pair<char,int>p2){
        return p1.second < p2.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char,int>mp, last_triggered;
        for(int i = 0; i < m; i++){
            mp[tasks[i]]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare>pq;
        for(auto it : mp){
            pq.push({it.first,it.second});
        }
        int cur_time = 0;
        while(!pq.empty()){
            vector<pair<char,int>>remaining_tasks;
            int x = n+1;
            while(x and !pq.empty()){
                int c = pq.top().first;
                int f = pq.top().second;
                pq.pop();
                f--;
                if(f)
                    remaining_tasks.push_back({c,f});
                cur_time++;
                x--;
            }
            for(auto it: remaining_tasks)
                pq.push(it);
            if(!pq.empty())
                cur_time += x;
        }
        return cur_time;
    }
};