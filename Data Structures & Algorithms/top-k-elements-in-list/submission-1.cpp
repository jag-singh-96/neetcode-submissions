class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;

        for(auto i : nums){
            map[i]++;
        }


        vector<int> ans;
        priority_queue<pair<int,int>> pq;


        for(auto m: map){
            
            pq.push({m.second,m.first});
        
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
    }
};
