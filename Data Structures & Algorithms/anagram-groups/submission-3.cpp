class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();

        unordered_map<string, vector<int>> map;
       
        vector<vector<string>> res;
        for(int i = 0; i < size; i++){
            string st = strs[i];
            vector<int> alphabet(26, 0);
            for(int j = 0; j < st.size(); j++){
                alphabet[st[j] - 'a']++;
            }

            string key;

            for(int j = 0; j < 26; j++){
                key += to_string(alphabet[j]) + "#";
            }

            map[key].push_back(i);
        }

        for(auto i: map){
            vector<int> index = i.second;
            vector<string> ans;
            for(int i = 0; i < index.size(); i++){
                ans.push_back(strs[index[i]]);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};
