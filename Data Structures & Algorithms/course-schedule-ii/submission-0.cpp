class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }


        vector<int> in(numCourses,0);


        for(int i = 0; i < numCourses; i++){
            for(auto x: adj[i]){
                in[x]++;
            }
        }


        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0){
                q.push(i);
            }
            
        }

        vector<int> ans;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto n: adj[node]){
                in[n]--;

                if(in[n] == 0){
                    q.push(n);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};

    }
};
