class Solution {
public:

    vector<string> res;
    void dfs(string s, unordered_set<string> set, vector<string> ans, int st){

        if(st == s.length()) {

            string str = "";
            int n = ans.size();
            for(int j = 0; j < n; j++){

                if(j != n-1){
                    str += ans[j] + " ";
                }else{
                    str += ans[j];
                }
            }

            res.push_back(str);
            return;
            
        } 


        string str = "";

        for(int i = st; i < s.length(); i++){
            
            str += s[i];

            if(set.find(str) != set.end()){
                ans.push_back(str);
                dfs(s,set,ans,i+1);
                ans.pop_back();

            }


        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> set;

        for(auto w: wordDict){
            set.insert(w);
        }

        vector<string> ans;

        dfs(s,set,ans,0);

        return res;

        
    }
};