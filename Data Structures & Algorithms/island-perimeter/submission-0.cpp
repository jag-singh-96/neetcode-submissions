class Solution {
public:

    // int dx[4] = {0,0,1,-1};
    // int dy[4] = {1,-1,0,0};
    // int get(vector<vector<int>>& grid, int n, int m, int i, int j){

    //     if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
    //         return 0;
    //     }

    //     grid[i][j] = 0;

    //     int count = 1;

    //     for(int i = 0; i < 4; i++){
    //         int ii = i+dx[i];
    //         int jj = j+dy[j];
    //         count += get(grid,n,m,ii,jj);
    //     }

    //     return count;

    // }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1){
                    count += 4;

                    if(i != 0 && grid[i-1][j] == 1){
                        count -=2;
                    }
                    if(j != 0 && grid[i][j-1] == 1){
                        count -=2;
                    }
                   
                }
            }
        }


        return count;
        
        
    }
};