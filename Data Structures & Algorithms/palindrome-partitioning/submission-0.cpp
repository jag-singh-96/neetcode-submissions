class Solution {
public:


    bool isP(string temp){

        int n = temp.size();
        int i = 0, j = n-1;

        while( i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }

    void m(string s,vector<vector<string>> &res, vector<string> &ans, int st){

        if(st == s.length()){
            res.push_back(ans);
            return;
        }

        string temp = "";

        for(int i = st; i < s.length(); i++){

            temp += s[i];

            if(isP(temp)){
                ans.push_back(temp);
                m(s,res,ans,i+1);
                ans.pop_back();
            }


        }

    }

    vector<vector<string>> partition(string s) {

        int n = s.length();

        vector<vector<string>> res;


        vector<string> ans;

        m(s,res,ans,0);

        return res;

        
        
    }
};
