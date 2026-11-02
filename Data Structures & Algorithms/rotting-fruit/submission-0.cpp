class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int freshCounts = 0;
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    freshCounts++;
                }
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                } 
            }
        }

        int count = 0;
        int tm = 0;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for(int k = 0; k < 4; k++){
                int ii = i+dx[k];
                int jj = j+dy[k];
                if(ii >= 0 && jj >= 0 && ii < n && jj < m && grid[ii][jj] == 1){
                    grid[ii][jj] = 2;
                    q.push({{ii,jj},t+1});
                    count++;
                }
            }

        }

        if(freshCounts != count) return -1;

        return tm;
    }
};
