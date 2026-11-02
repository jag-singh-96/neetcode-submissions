class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();

        unordered_map<char, int> map;

        for(auto c:  t){
            map[c]++;
        }

        int desired = map.size();

        int found = 0;

        unordered_map<char, int> wMap;

        int l = 0;

        int maxlen = INT_MAX, start = 0;

        for(int r = 0; r < n; r++){
            wMap[s[r]]++;


            if(map.find(s[r]) != map.end() && wMap[s[r]] == map[s[r]]) found++;

            while(found == desired){

                int len = r-l+1;
                if(len < maxlen){
                    maxlen = len;
                    start = l;
                }
                wMap[s[l]]--;
                if(map.find(s[l]) != map.end() && wMap[s[l]] < map[s[l]]) found--;
                l++;
            }


        }

        return maxlen == INT_MAX ? "" : s.substr(start,maxlen);


        
    }
};
