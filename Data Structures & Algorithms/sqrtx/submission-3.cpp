class Solution {
public:
    int mySqrt(int x) {

        int i = 1, j = x;

        if(x == 0) return 0;

        int res = 0;

        while(i <= j){

            // cout<<i<<"-- "<<j<<endl;

            int mid = i + (j-i)/2;

            if(mid == x/mid){
                res =  mid;
                return res;
            }
            if(mid > x/mid){
                
                j = mid-1;
            }else{
                res = mid;
                i = mid+1;
            }


        }

        return res;
        
    }
};