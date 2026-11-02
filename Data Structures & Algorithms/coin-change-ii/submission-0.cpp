class Solution {
public:


    int get(int amount, vector<int>& coins, int n){

        if(amount == 0){
            return 1;
        }

        if(n == 0){
            return 0;
        }

        if(coins[n-1] > amount){
             return get(amount,coins, n-1);
        }

         return get(amount-coins[n-1],coins, n) + get(amount,coins, n-1);

    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        // return get(amount,coins, n);


        vector<int> dp(amount+1,0);

        dp[0] = 1;


        for(int i = 0 ; i < n; i++){
            for(int j = 0; j <= amount; j++){
                if(coins[i] <= j){
                    dp[j] += dp[j-coins[i]];
                }
                
            }
        }

        return dp[amount];
        
    }
};
