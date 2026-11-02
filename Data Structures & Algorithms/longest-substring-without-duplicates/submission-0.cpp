class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        unordered_map<int, int> map;

        int ans = 0;

        int l = 0;
        for(int r = 0; r < n; r++){

            while(map.find(s[r]) != map.end()){
                
                map[s[l]]--;
                if(map[s[l]] == 0){
                    map.erase(s[l]);
                }
                l++;
            }

            ans = max(ans,r-l+1);

            map[s[r]]++;

        }

        return ans;
    }
};
