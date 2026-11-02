class Solution {
public:

vector<vector<int>> dp;

    int get(vector<int>& nums, int n, int s, int e){

        if(s > e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        int res = INT_MIN;
        
        for(int k = s; k <= e; k++){

            int product = nums[s-1]*nums[k]*nums[e+1];

            int sum = get(nums,n,s,k-1)+get(nums,n,k+1,e)+product;

            res = max(res, sum);

        }

        return dp[s][e]=res;


    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        
        dp.resize(n+1,vector<int>(n+1,-1));
        return get(nums,n,1,n);
        
    }
};
