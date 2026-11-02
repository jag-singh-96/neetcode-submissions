class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<int> dp(amount+1,INT_MAX);

        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount; j++){
                if(coins[i] <= j && dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j],1+dp[j-coins[i]]);
                }
                
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
        

        // vector<vector<int>> dp(n+1,vector<int>(amount+1,0));


        // for(int i = 0 ; i <= amount; i++){
        //     dp[0][i] = INT_MAX;
        // }

        // dp[0][0] = 0;


        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= amount; j++){
        //         if(coins[i-1] > j){
        //             dp[i][j] = dp[i-1][j];
        //         }else{

        //             int include = dp[i][j-coins[i-1]];
        //             if(include != INT_MAX){
        //                 include = include+1;
                        
        //             }

        //             dp[i][j] = min(include,dp[i-1][j]);
                    
        //         }
        //     }
        // }

        // return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
        
    }
};
