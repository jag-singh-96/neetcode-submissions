class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // pair<int, int> pq;

        for(auto t: trips){
            pq.push({t[1],t[0]});
            pq.push({t[2],-1*t[0]});
        }

        int sum = 0;

        while(!pq.empty()){
            
            pair<int, int> p = pq.top();
            pq.pop();

            sum += p.second;

            if(sum > capacity) return false;

        }

        return true;
        
    }
};