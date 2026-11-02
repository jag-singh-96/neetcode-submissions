class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp;

        dp.push_back(nums[0]);

        for(int i = 1; i < n; i++){

            auto index = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();

            if(index == dp.size()){
                dp.push_back(nums[i]);
            }else{
                dp[index] = nums[i];
            }

            

        }

        return dp.size();
        
    }
};
