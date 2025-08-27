class Twitter {
public:
    int time; // global timestamp
    unordered_map<int, unordered_set<int>> following; // who each user follows
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> {time, tweetId}

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // (time, tweetId)

        // include user's own tweets
        for (auto &t : tweets[userId]) {
            pq.push(t);
        }

        // include followees' tweets
        for (int followee : following[userId]) {
            for (auto &t : tweets[followee]) {
                pq.push(t);
            }
        }

        // get top 10 most recent
        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // cannot follow self
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
