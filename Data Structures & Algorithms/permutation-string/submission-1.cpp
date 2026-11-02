class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();

        int n2 = s2.length();


        unordered_map<char, int> map1;
        unordered_map<char, int> map2;


        for(auto ch: s1){
            map1[ch]++;
        }


        for(int i = 0; i < n1; i++){
            map2[s2[i]]++;
        }

        if(map1 == map2) return true;

        
        for(int i = n1; i < n2; i++){

            map2[s2[i-n1]]--;

            if(map2[s2[i-n1]] == 0){
                map2.erase(s2[i-n1]);
            }

            map2[s2[i]]++;

            if(map1 == map2) return true;


        }


        return false;

        
    }
};
