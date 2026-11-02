class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;

        for(auto n : nums){
            sum += n;
        }

        int total = (sum + target);

        if(total % 2 == 1 || target > total || total < 0) return false;

        total = total/2;

        vector<vector<int>> dp(n+1,vector<int>(total+1,0));


        dp[0][0] = 1;


        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= total; j++){
                if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }
        
        return dp[n][total];

    }
};
