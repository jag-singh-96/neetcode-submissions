class Solution {
public:

    unordered_map<int, bool> map;
    bool dfs(string s,unordered_set<string> set, int st){

        if(st == s.length()){
            return true;
        }


        string str = "";

        if(map.find(st) != map.end()){
            return map[st];
        }
        

        for(int i = st; i < s.length(); i++){

            str += s[i];

            if(set.find(str) != set.end()){
                bool b = dfs(s,set,i+1);
                map[st] = b;
                if(b) return true;
            }

        }
        map[st] = false;
        return false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> set;

        for(auto w: wordDict){
            set.insert(w);
        }

        return dfs(s,set,0);

        
        
    }
};
