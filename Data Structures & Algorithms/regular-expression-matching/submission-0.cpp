class Solution {
public:

    unordered_map<string , int> map;

    bool get(string s, string p, int n, int m){


        if(m == 0 && n == 0) return true;

        if(n > 0 && m == 0) return false;

        if(n == 0 && m > 0){
            

            if(m >= 2 && p[m-1] == '*'){
                return get(s,p,n,m-2);
            }

            return false;

        }

        string key = to_string(n) + " #" + to_string(m) + " #";

        if(map[key] > 0){
            return map[key];
        }

        if(s[n-1] == p[m-1] || p[m-1] == '.'){
            return map[key] = get(s,p,n-1,m-1);
        }

        if(p[m-1] == '*'){
            bool zero = get(s,p,n,m-2);

            bool non_zero = false;
            if(p[m-2] == '.' || p[m-2] == s[n-1]){
                non_zero = get(s,p,n-1,m);
            }

            return map[key] = zero || non_zero;

        }

        return false;

    }

    bool isMatch(string s, string p) {

        int n = s.length();

        int m = p.length();


        return get(s,p,n,m);
        
    }
};
