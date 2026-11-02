class Solution {
public:

    void m(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &ans, int st){

        if(target == 0){
            res.push_back(ans);
        }


        for(int i = st; i < candidates.size(); i++){

            
            if(i > st && candidates[i-1] == candidates[i]) continue;

            if(target - candidates[i] < 0) break;

            ans.push_back(candidates[i]);
            m(candidates, target-candidates[i], res, ans, i+1);
            ans.pop_back();

        }

    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;

        vector<int> ans;


        m(candidates, target, res, ans, 0);


        return res;


        
    }
};
