class Solution {
public:

    void m(vector<int>& nums, int target, int st, vector<int> &ans, vector<vector<int>> &res){

        if(target == 0){
            res.push_back(ans);
            return;
        }

        for(int i = st; i < nums.size(); i++){

            if(target - nums[i] < 0){
                break;
            }

            ans.push_back(nums[i]);

            m(nums,target-nums[i], i, ans,res);

            ans.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> ans;

        vector<vector<int>> res;

        m(nums,target, 0, ans,res);

        return res;

        
    }
};
