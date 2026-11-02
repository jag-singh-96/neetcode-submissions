class Solution {
public:
    unordered_map<string, int> map;
    int get(string s1, string s2, int n, int m){

        if(n == 0){
            return m;
        }

        if(m == 0){
            return n;
        }

        string key = to_string(n) + " #" + to_string(m) + " #";

        if(map[key] > 0){
            return map[key];
        }

        if(s1[n-1] == s2[m-1]){
            return get(s1,s2,n-1,m-1);
        }

        int insert = get(s1,s2,n,m-1);

        int remove = get(s1,s2,n-1,m);

        int replace = get(s1,s2,m-1,n-1);

        return map[key] = 1+min(insert, min(remove, replace));

    }


    int minDistance(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();


        return get(s1,s2,n,m);
        
    }
};
