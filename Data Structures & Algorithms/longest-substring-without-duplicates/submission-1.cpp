class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int i = 0;

        unordered_map<int,int> map;

        int len = 0;
        
        for(int j = 0; j < n; j++){

            while(map.find(s[j]) != map.end()){
                map[s[i]]--;
                
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
                
            }
            len = max(len, j-i+1);
            map[s[j]]++;
        }

        return len;

        
    }
};
