class Solution {
public:
    
     unordered_map<string, int> map;

    bool get(string s1, string s2, string s3, int n1, int n2){

        if(n1 == 0 && n2 == 0) return true;

        string st = to_string(n1) + "_#" + to_string(n2) + "_#";

        if(map.find(st) != map.end()) return map[st];

        bool b1 = false, b2 = false;
        if(n1 > 0 && s1[n1-1] == s3[(n1+n2)-1]){
             b1 = get(s1,s2,s3,n1-1,n2);
        }

        if(n2 > 0 && s2[n2-1] == s3[(n1+n2)-1]){
             b2 =  get(s1,s2,s3,n1,n2-1);
        }

        return map[st] = b1 || b2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if(n2 + n1 != n3) return false;

       

        return get(s1,s2,s3,n1,n2);
        
    }
};
