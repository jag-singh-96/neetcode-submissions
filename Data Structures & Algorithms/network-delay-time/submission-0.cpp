class Solution {
public:

    typedef pair<int, int> p;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        unordered_map<int, vector<p>> map;

        vector<int> result(n+1,INT_MAX);

        for(auto t: times){
            map[t[0]].push_back({t[1],t[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;

        pq.push({0,k});

        result[k] = 0;

        while(!pq.empty()){
            
            int dist = pq.top().first;
            int src = pq.top().second;
            pq.pop();


            for(auto d: map[src]){
                if(dist + d.second < result[d.first]){
                    result[d.first] = dist + d.second;
                    pq.push({result[d.first],d.first});
                }   
            }

        }

        int maxDist = 0;

        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) {
                return -1;
            }

            maxDist = max(maxDist, result[i]);
        }


        return maxDist;


    }
};
