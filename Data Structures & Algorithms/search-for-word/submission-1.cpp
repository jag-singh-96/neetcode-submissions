class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool get(vector<vector<char>>& board, string word, int i, int j, int n, int m, string &st){

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#'){
            return false;
        }

        st.push_back(board[i][j]);
        char temp = board[i][j];

        board[i][j] = '#';

        if(st == word) return  true;

        for(int k = 0; k < 4; k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            
            bool b = get(board, word,ii,jj,n,m,st);
            if(b) return true;
        }

        board[i][j] = temp;
        st.pop_back();
        return false;

        

    }

    bool exist(vector<vector<char>>& board, string word) {


        int n = board.size();

        int m = board[0].size();

        string st;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(board[i][j] == word[0]){
                    bool b = get(board, word,i,j,n,m,st);
                    if(b) return true;
                }

            }

        }

        return false;
        
    }
};
