class Twitter {
    struct User {
        vector<pair<int, int>> tweets;
        unordered_set<int> followees;
    };
    
    unordered_map<int, User> users;
    int t;
public:
    /** Initialize your data structure here. */
    Twitter() {
        t = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto &tweets = users[userId].tweets;
        tweets.push_back(make_pair(++t, tweetId));
        //cout << "post tweet " << tweets.back().first << " " << tweets.back().second << endl;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> tweets;
        vector<int> feed;

        // gather own tweets
        //if (users[userId].tweets.size() <= 10)
            tweets = users[userId].tweets;
        //else
        //    tweets.insert(tweets.end(), users[userId].tweets.begin(), users[userId].tweets.begin() + 10);
        // gather all followee tweets
        for (auto &followeeId : users[userId].followees) {
            auto user = users[followeeId];
            //if (user.tweets.size() <= 10)
                tweets.insert(tweets.end(), user.tweets.begin(), user.tweets.end());
            //else
            //    tweets.insert(tweets.end(), user.tweets.begin(), user.tweets.begin() + 10);
        }
        make_heap(tweets.begin(), tweets.end());
        for (int i = 0; i < 10; i++) {
            if (tweets.empty())
                break;
            pop_heap(tweets.begin(), tweets.end());
            feed.push_back(tweets.back().second);
            tweets.pop_back();
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            users[followerId].followees.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            users[followerId].followees.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
