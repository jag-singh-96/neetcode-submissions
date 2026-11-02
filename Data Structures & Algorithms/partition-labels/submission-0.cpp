class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> map;

        int n = s.length();

        for(int i = 0; i < n; i++){

            map[s[i]] = i;

        }


        int last = map[s[0]];
        vector<int> ans;
        int l = 0;
        for(int i = 0; i < n; i++){
            last = max(last, map[s[i]]);

            if(last == i){
                ans.push_back(i-l+1);
                l = i+1;
            }

        }

        return ans;
        
    }
};
