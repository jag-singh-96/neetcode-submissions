class Solution {
public:

    typedef pair<int, pair<int, int>> p;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        unordered_map<int,vector<pair<int,int>>> adj;
        
        vector<vector<int>> res(n, vector<int>(k + 2, INT_MAX));

        for(auto f: flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;

        pq.push({0,{src,0}});

        res[src][0] = 0;


        while(!pq.empty()){

            int cost = pq.top().first;
            int node = pq.top().second.first;
            int stop = pq.top().second.second;
            pq.pop();

            if(node == dst) return cost;

            if(stop > k) continue;

            for(auto n: adj[node]){
                int newCost = n.second;
                int nextStop = stop + 1;
                if(cost + newCost < res[n.first][nextStop]){
                    res[n.first][nextStop] = cost + newCost;
                    pq.push({res[n.first][nextStop],{n.first,nextStop}});
                }
            }

        }

        return -1;

    }
};
