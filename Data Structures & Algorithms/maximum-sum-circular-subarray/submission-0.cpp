class Solution {
public:

    int get(vector<int> nums){

        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i-1]+ nums[i] , nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;

    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(),0);

        int max1 = get(nums);

        for(int i = 0; i < n; i++){
            nums[i] = -1*nums[i];
        }

        
        int max2 = get(nums);


        if(sum+max2 != 0 && sum+max2 > max1) return sum+max2;

        return max1;


        
    }
};