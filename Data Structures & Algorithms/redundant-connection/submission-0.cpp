class Solution {
public:

    vector<int> parents;
    vector<int> rank;


    int parent(int node){

        if(parents[node] == node){
            return node;
        }

        return parent(parents[node]);
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        rank.resize(n+1);

        parents.resize(n+1);

        for(int i = 0; i < n; i++){
            parents[i] = i;
        }

        for(auto e: edges){

            int px = parent(e[0]);
            int py = parent(e[1]);

            if(px == py) return {e[0],e[1]};


            if(rank[px] >= rank[py]){
                parents[px] = py;
            }else {
                parents[py] = px;
            }

        }


        return {};

        
    }
};
