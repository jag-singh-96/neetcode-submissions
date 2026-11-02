class Solution {
public:

    vector<int> parent;

    vector<int> rank;

    int p(int node){

        if(parent[node] == node){
            return node;
        }

        return p(parent[node]);

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        
        parent.resize(n);
        rank.resize(n,0);


        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto e: edges){

            int px = p(e[0]);
            int py = p(e[1]);

            if(rank[px] > rank[py]){
                parent[py] = px;
                rank[px]++;
            }else if(rank[px] < rank[py]){
                parent[px] = py;
                rank[py]++;
            }else{
                parent[py] = px;
                rank[px]++;
            }

        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(parent[i] == i) {
                count++;
            }
        }
        return count;

    }
};
