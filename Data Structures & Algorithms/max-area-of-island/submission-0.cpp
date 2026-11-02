class Solution {
public:

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    int get(vector<vector<int>>& grid, int i , int j, int n, int m){


        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1){
            return 0;
        }

        grid[i][j] = 2;

        int count = 1;

        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];

            count += get(grid,ii,jj,n,m);

        }

        // grid[i][j] = 1;
        return count;



    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

        int maxArea = 0;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int count = get(grid,i,j,n,m);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;

        
    }
};
