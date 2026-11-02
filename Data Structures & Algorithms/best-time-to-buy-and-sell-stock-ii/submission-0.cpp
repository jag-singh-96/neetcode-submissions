#include<bits/stdc++.h>
class Solution {
public:
     int dp[100001][2];
    int m(vector<int>& prices, int index, int op){


        if(index == prices.size()){
            return 0;
        }

        if (dp[index][op] != -1) {
            return dp[index][op];
        }

        int profit = 0;

        if(op == 1){
            profit += max(-1*prices[index] + m(prices, index+1, 0),0+m(prices, index+1, 1));
        }else{
            profit += max(prices[index] + m(prices, index+1, 1), 0 + m(prices, index+1, 0));
        }
        
        return dp[index][op] = profit;

    }

    int maxProfit(vector<int>& prices) {

        
        memset(dp, -1, sizeof(dp));
        return m(prices, 0, 1);
        
    }
};