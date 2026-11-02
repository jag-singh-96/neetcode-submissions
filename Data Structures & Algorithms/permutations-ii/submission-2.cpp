class Solution {
public:

    void m(vector<int>& nums, int st, vector<vector<int>> &res){

        if(st == nums.size()){

            res.push_back(nums);
            return;
        }

        unordered_set<int> set;
        for(int i = st; i < nums.size(); i++){

            if(set.count(nums[i]) > 0) continue;

            set.insert(nums[i]);

            swap(nums[i], nums[st]);

            m(nums,st+1,res);

            swap(nums[i], nums[st]);
        }


    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        m(nums,0,res);

        return res;

        
    }
};