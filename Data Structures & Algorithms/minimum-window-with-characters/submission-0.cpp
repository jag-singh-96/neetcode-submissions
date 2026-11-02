class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mapt;

        for(auto i: t){
            mapt[i]++;
        }

        int l = 0, r = 0;

        int size = mapt.size();

        int minlen = INT_MAX;

        int st = 0;

         int desire = 0;

        unordered_map<char, int> maps;

        while(r<s.size()){
            maps[s[r]]++;

            if(mapt.find(s[r]) != mapt.end() && mapt[s[r]] == maps[s[r]]) desire++;

            while(size==desire){

                int len = r-l+1;

                if(len < minlen){
                    st = l;
                    minlen = len;
                }

                maps[s[l]]--;
                if(mapt.find(s[l]) != mapt.end() && mapt[s[l]] > maps[s[l]]) desire--;

                l++;

            }
            r++;

        }

        return minlen == INT_MAX ? "" : s.substr(st, minlen);
        
    }
};
