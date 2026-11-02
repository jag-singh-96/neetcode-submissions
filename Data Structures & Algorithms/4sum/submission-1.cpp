class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;

        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;
            int fi = nums[i];
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int s = nums[j];

                int k = j+1, l = n-1;

                while(k < l){
                    int t = nums[k];
                    int fo = nums[l];

                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == (long long)target){
                        res.push_back({fi,s,t,fo});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }else if(sum > target){
                        l--;
                    }else{
                        k++;
                    }

                    // while(k < l && nums[k] == nums[k-1]){
                    //     k++;
                    // }

                    // while(k < l && nums[l] == nums[l+1]) {
                    //     l--;
                    // }

                }
            }
        }

        return res;
        
    }
};