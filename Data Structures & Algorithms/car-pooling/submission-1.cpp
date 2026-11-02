class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int, int>> v;

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        for(auto i: trips){

            pq.push({i[1],i[0]});
            pq.push({i[2],-1*i[0]});

        }


        int sum = 0;

        while(!pq.empty()){

            sum += pq.top().second;
            pq.pop();

            if(sum > capacity) return false;

        }
        

        return true;

        
    }
};