class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};

    void mo(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m){

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || vis[i][j] == 1 ){
            return;
        }

        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            mo(grid,vis,ii,jj,n,m);
        }



    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    mo(grid,vis,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
        
    }
};
