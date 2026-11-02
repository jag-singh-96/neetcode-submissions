class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i+1, k = n-1;
            while(j < k){
                int f = nums[i], s = nums[j], t = nums[k];
                int sum = f+s+t;
                if(sum == 0){
                   res.push_back({f,s,t});
                   while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k-1] == nums[k]) k--;
                   j++,k--;
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }

                

            }
        }

        return res;
    }
};
