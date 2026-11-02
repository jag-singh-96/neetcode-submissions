class Twitter {
public:

    int curr = 0;

    unordered_map<int, set<int>> friends;

    unordered_map<int,vector<pair<int,int>>> tweet;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweet[userId].push_back({curr++,tweetId});


    }
    
    vector<int> getNewsFeed(int userId) {


        vector<int> ans;

        priority_queue<pair<int,int>> userT;


        for(auto t: tweet[userId]){
            userT.push(t);
        }

        for(auto followeeId: friends[userId]){
            for(auto t: tweet[followeeId]){
                userT.push(t);
            }
        }

        int count = 0;

        while(!userT.empty() && count < 10){

            ans.push_back(userT.top().second);
            userT.pop();
            count++;

        }


        return ans;

        
    }
    
    void follow(int followerId, int followeeId) {

        if(followerId != followeeId){
            friends[followerId].insert(followeeId);
        }
        
        
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
