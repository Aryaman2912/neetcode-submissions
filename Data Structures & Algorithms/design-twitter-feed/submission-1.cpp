class Twitter {
public:
    int ind;
    unordered_map<int,int>index_to_tweet;
    unordered_map<int,vector<int>>tweets;
    unordered_map<int,set<int>>followers;
    unordered_map<int, set<int>>news_feed;
    Twitter() {
        ind = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        index_to_tweet[ind] = tweetId;
        tweets[userId].push_back(ind);
        news_feed[userId].insert(ind);
        for(auto x: followers[userId]){
            news_feed[x].insert(ind);
        }
        ind++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        int t = 10;
        for(auto it = news_feed[userId].rbegin(); res.size() != 10 and it != news_feed[userId].rend(); it++){
            res.push_back(index_to_tweet[*it]);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        followers[followeeId].insert(followerId);
        for(auto x : tweets[followeeId]){
            news_feed[followerId].insert(x);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        followers[followeeId].erase(followerId);
        for(auto x : tweets[followeeId]){
            news_feed[followerId].erase(x);
        }
    }
};
