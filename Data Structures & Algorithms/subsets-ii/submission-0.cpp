class Solution {
public:


    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &ans, int st){

        res.push_back(ans);

        for(int i = st; i < nums.size(); i++){

            if(i != st && nums[i] == nums[i-1]) continue;

            ans.push_back(nums[i]);

            dfs(nums,res, ans, i+1);

            ans.pop_back();
        }



    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        vector<int> ans;

        dfs(nums,res, ans, 0);

        return res;

        
    }
};
