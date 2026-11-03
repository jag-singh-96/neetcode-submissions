class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> in(numCourses,0);

        for(int i = 0; i < numCourses; i++){
            for(auto x: adj[i]){
                in[x]++;
            }
        }

        
        

        queue<int> q;

        vector<int> v;

        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            v.push_back(node);

            for(auto x: adj[node]){
                in[x]--;
                if(in[x] == 0){
                    q.push(x);
                }
            }
        }

        if(numCourses == v.size()) return true;
        return false;

    }
};
