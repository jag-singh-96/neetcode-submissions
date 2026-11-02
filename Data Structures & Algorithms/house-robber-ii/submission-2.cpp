class Solution {
public:


    int m(vector<int>& nums, int i , int j){

        int len = j-i+1;

        vector<int> dp(len,0);


        dp[0] = nums[i];

        if(len == 1)
            return dp[0];

        dp[1] = max(nums[i], nums[i + 1]);

        for(int k = 2; k < len; k++){
            dp[k] = max(dp[k-2]+nums[i+k],dp[k-1]);
        }

        return dp[len-1];

    }


    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        int max1 = m(nums,0,n-2);

        int max2 = m(nums,1, n-1);

        return max(max1, max2);
        
    }
};
