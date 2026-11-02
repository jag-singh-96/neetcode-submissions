class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board.size();

        unordered_map<string, int> map;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == '.') continue;

                string row = "row" + to_string(i) + to_string(board[i][j]);

                string col = "col" + to_string(j) + to_string(board[i][j]);

                string box = "box" + to_string(((i/3)*3) + (j/3)) + to_string(board[i][j]);

                if(map[row] > 0 || map[col] > 0 || map[box] > 0){
                    return false;
                }


                map[row]++;
                map[col]++;
                map[box]++;
            }
        }
        return true;
    }
};
