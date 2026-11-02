class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // priority_queue<int, vector<int>,greater<int>> pq;

        priority_queue<pair<double,int>> pq;

        unordered_map<double, int> map;

        int n = points.size();

        for(int i = 0; i < k; i++){
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({distance,i});
        }

        for(int i = k; i <  n; i++){
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            
            if(pq.top().first > distance){
                pq.pop();
                pq.push({distance,i});
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;

        
    }
};
