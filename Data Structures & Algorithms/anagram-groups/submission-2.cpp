class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();

        unordered_map<string, vector<int>> map;
        vector<vector<string>> res;
        for(int i = 0; i < size; i++){
            string st = strs[i];
            sort(st.begin(), st.end());
            map[st].push_back(i);
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
