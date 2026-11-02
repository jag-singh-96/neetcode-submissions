class Solution {
public:
    unordered_map<int, bool> dp;
    bool m(string s,  unordered_set<string> set, int st){

        if(st == s.length()){
            return true;
        }

        if(dp.find(st) != dp.end()) return dp[st];


        string temp = "";

        for(int i = st; i < s.length(); i++){
            temp += s[i];
            if(set.find(temp) != set.end()){
                bool b = m(s,set,i+1);
                if(b) return dp[st] =  true;
            }
        }
        return dp[st] = false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = wordDict.size();

        int st = 0;

        unordered_set<string> set;


        for(auto w: wordDict){
            set.insert(w);
        }

        dp.clear();

        bool b = m(s,set,st);
        
        return b;
    }
};
