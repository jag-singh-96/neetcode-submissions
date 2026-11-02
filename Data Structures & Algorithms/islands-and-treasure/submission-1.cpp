class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        

        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int step = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int ii = i+dx[k];
                int jj = j+dy[k];
                if(ii >= 0 && jj >= 0 && ii < n && jj < m && grid[ii][jj] == INT_MAX){
                    grid[ii][jj] = step+1;
                    q.push({{ii,jj},step+1});
                }
            }
        }

    }
};
