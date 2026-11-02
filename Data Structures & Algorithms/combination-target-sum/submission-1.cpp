class Solution {
public:

    void m(vector<int>& nums, int target, vector<int> &ans, vector<vector<int>> &res, int st){

        if(target == 0){

            res.push_back(ans);
            return;
        }

        
        for(int i = st; i < nums.size(); i++){

            if(target-nums[i] < 0){
              break;  
            }

            // target -= nums[i];
            ans.push_back(nums[i]);
            m(nums,target - nums[i] , ans, res, i);
            ans.pop_back();

        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> ans;

        vector<vector<int>> res;

        m(nums, target, ans, res, 0);

        return res;
        
    }
};
