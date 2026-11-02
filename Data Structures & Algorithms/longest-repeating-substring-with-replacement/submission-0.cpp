class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int maxf = 0;

        unordered_map<char, int> map;

        int l = 0;

        int res = 0;
        for(int r = 0; r < n; r++){

            map[s[r]]++;

            maxf = max(maxf, map[s[r]]);

            int len = r-l+1;

            if(len - maxf > k){
                map[s[l]]--;
                if(map[s[l]] == 0){
                    map.erase(s[l]);
                }
                l++;
            }

            res = max(res, r-l+1);

        }

        return res;
        
    }
};
