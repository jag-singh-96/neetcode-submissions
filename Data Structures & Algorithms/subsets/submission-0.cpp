class Solution {
public:

    void m(vector<int>& nums, vector<int> &ans, vector<vector<int>> &res, int st){


        res.push_back(ans);

        for(int i = st; i < nums.size(); i++){
            ans.push_back(nums[i]);
            m(nums,ans, res,i+1);
            ans.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        vector<vector<int>> res;


        m(nums,ans, res,0);

        return res;
    }
};
