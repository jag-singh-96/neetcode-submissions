class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int p(int node){

        if(node == parent[node]){
            return node;
        }

        return p(parent[node]);
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        parent.resize(n+1);

        rank.resize(n+1,0);

        if(edges.size() != n - 1)

            return false;

        for(int i = 0 ; i < n; i++){
            parent[i] = i;
        }


        for(auto e: edges){
            int px = p(e[0]);
            int py = p(e[1]);

            if(px == py) return false;


            if(rank[px] > rank[py]){
                parent[py] = px;
                rank[px]++;
            }else if(rank[px] < rank[py]){
                parent[px] = py;
                rank[py]++;
            }else {
                parent[px] = py;
                rank[px]++;
            }
        }
        return true;

    }
};
