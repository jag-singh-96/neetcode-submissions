class Solution {
public:

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    void dfs(vector<vector<char>>& board,vector<vector<bool>> &vis, int i, int j, int n, int m){

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O' || vis[i][j] == true){
            return;
        }

        vis[i][j] = true;

        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            dfs(board,vis,ii,jj,n,m);


        }

    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();


        vector<vector<bool>> vis(n,vector<bool>(m+1,false));

        for(int i = 0; i < n; i++){
            if(vis[i][0] == false && board[i][0] == 'O'){
                dfs(board,vis,i,0,n,m);
            }
        }

        for(int i = 0; i < m; i++){
            if(vis[n-1][i] == false && board[n-1][i] == 'O'){
                dfs(board,vis,n-1,i,n,m);
            }
        }

        for(int i = 0; i < n; i++){
            if(vis[i][m-1] == false && board[i][m-1] == 'O'){
                dfs(board,vis,i,m-1,n,m);
            }
        }

        for(int i = 0; i < m; i++){
            if(vis[0][i] == false && board[0][i] == 'O'){
                dfs(board,vis,0,i,n,m);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == false && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
