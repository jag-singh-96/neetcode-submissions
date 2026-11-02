class Solution {
public:

    void m(int n, vector<string> &res, string ans, int o, int c){

        if(o == n && c==n){
            res.push_back(ans);
            return;
        }

        if( o < n){
            // ans.push_back('(');
            m(n,res,ans+'(',o+1,c);
        }

        if(c<o && c<n){
            // ans.push_back(')');
            m(n,res,ans+')',o,c+1);
        }

        // ans.pop_back();


    }

    vector<string> generateParenthesis(int n) {

        
        vector<string> res;

        string ans;

        m(n,res,ans,0,0);


        return res;
        
        
    }
};
