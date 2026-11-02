class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        unordered_map<string, vector<string>> map;


        for(int i = 0; i < n; i++){

            string str = strs[i];

            vector<int> ch(26,0);

            for(auto c: str){
                ch[c-'a']++;
            }

            string s;

            for(int i = 0; i < 26; i++){
                s += to_string(ch[i]) + "#";
            }

            map[s].push_back(strs[i]);

        }

        vector<vector<string>> res;

        for(auto m: map){

            res.push_back(m.second);

        }

        return res;


    }
};
