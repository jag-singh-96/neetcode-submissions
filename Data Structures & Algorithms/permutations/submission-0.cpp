class Solution {
public:


    void m(vector<int>& nums, int st,  vector<vector<int>> &res){

        if(st == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = st; i < nums.size(); i++){

            swap(nums[st], nums[i]);

            m(nums,st+1,res);

            swap(nums[st], nums[i]);

        }

    }


    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();


        // vector<int> ans;

        vector<vector<int>> res;

        m(nums,0,res);

        return res;

        
    }
};
