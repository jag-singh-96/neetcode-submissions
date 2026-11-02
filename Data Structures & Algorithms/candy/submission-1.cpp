class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> candy(n,0);

        candy[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i]){
                candy[i] += candy[i-1]+1;
            }else{
                candy[i] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            cout<<candy[i]<<" ";
        }

        for(int i = n-2; i >= 0; i--){
            if(ratings[i]>ratings[i+1]){
                if(candy[i] <= candy[i+1]) candy[i] = candy[i+1]+1;
            }
        }


        return accumulate(candy.begin(),candy.end(),0);
        
    }
};