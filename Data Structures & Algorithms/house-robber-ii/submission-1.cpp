class Solution {
public:

    int get(vector<int>& nums, int s, int e){

        vector<int> dp((e-s)+1,0);

        int n = dp.size();

        dp[0] = nums[s];        

        if(s == e) return dp[0];

        dp[1] = max(dp[0],nums[s+1]);

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i+s]);
            cout<<dp[i]<<endl;
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)  return nums[0];

        int max1 = get(nums,0,n-2);

        int max2 = get(nums,1,n-1);

        // cout<<max2<<endl;
        // return 0;
        return max(max1,max2);
        
        
        
    }
};
