class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(vector<vector<int>>& heights, int i, int j, int n, int m, vector<vector<int>>& ocean, int prev){

        if(i < 0 || j < 0 || i >= n || j >= m || ocean[i][j] == 1 || heights[i][j] < prev){
            return;
        }

        ocean[i][j] = 1;

        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            dfs(heights,ii,jj,n,m,ocean,heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> ao(n,vector<int>(m,0));
        vector<vector<int>> po(n,vector<int>(m,0));

        for(int i = 0; i < m; i++){
            dfs(heights,0,i,n,m,po,-1);
        }
        
        for(int i = 0; i < n; i++){
            dfs(heights,i,0,n,m,po,-1);
        }

        for(int i = 0; i < n; i++){
            dfs(heights,i,m-1,n,m,ao,-1);
        }

        for(int i = 0; i < m; i++){
            dfs(heights,n-1,i,n,m,ao,-1);
        }

        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ao[i][j] == 1 && po[i][j] == 1){
                    res.push_back({i,j});
                }
            }
        }

        return res;

    }
};
