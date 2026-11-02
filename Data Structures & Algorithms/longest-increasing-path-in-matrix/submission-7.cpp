class Solution {
public:

    int dx[4] = {0,0,-1,1};

    int dy[4] = {1,-1,0,0};

    unordered_map<string , int> map;

    int dfs(vector<vector<int>>& matrix, int n, int m, int i, int j, int prev){

        if(i >= n || j >= m || i < 0 || j < 0 || matrix[i][j] <= prev ){
            return 0;
        }

        int len = 1;

        // int temp = matrix[i][j];
        //matrix[i][j] = -1;
        string key =  to_string(i) + " #" + to_string(j) + " #";


        if(map.find(key) != map.end()) return map[key];


        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];

            
            len = max(len , 1+ dfs(matrix, n,m,ii,jj, matrix[i][j]));
        }

       // matrix[i][j] = temp;
    //  what haooened un toronto also 
        return map[key] = len;





    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int m = matrix[0].size();

        int maxlen = 0;

        int prev = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int len = dfs(matrix, n,m,i,j, prev);
                maxlen = max(len, maxlen);
                
            }
        }
        

        return maxlen;
    }
};
