class Solution {
public:

    void get(int n, int k, vector<vector<int>> &res, vector<int> &ans, int st){

        if(k==0){
            res.push_back(ans);
        }


        for(int i = st; i <= n; i++){

            ans.push_back(i);
            get(n,k-1,res,ans,i+1);
            ans.pop_back();

        }


    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;

        vector<int> ans;


        get(n,k,res,ans,1);

        return res;


        
    }
};