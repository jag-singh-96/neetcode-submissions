class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int n = matrix.size();

        int m = matrix[0].size();


        int fc = 0, fr = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][0] == 0 && j == 0){
                    fc = 1;
                }

                if(matrix[0][j] == 0 && i == 0){
                    fr = 1;
                }

                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

            }
        }


        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(fr == 1){
            for(int i = 0; i < m; i++){
                matrix[0][i] = 0;
            }
        }

        if(fc == 1){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }



    }
};
