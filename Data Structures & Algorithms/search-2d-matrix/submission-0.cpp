class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();

        int m = matrix[0].size();

        // cout<<n<<"--"<<m<<endl;


        int s = 0, e = (n*m) - 1;


        while(s <= e){
            int mid = (s+e)/2;

            int i = mid/m;
            int j = mid%m;
            // cout<<mid<<endl;

            // cout<<i<<"--"<<j<<endl;

            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            
        }

        return false;
        
    }
};
