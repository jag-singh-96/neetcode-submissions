class Solution {
public:

    vector<vector<int>> dp;
    int get(string s, string t, int n, int m){

        if(n == 0 && m == 0) return 1;

        if(n==0) return 0;

        if(m==0) return 1;

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(s[n-1] != t[m-1]){
            return dp[n][m] = get(s,t,n-1,m);
        }

        return dp[n][m] = get(s,t,n-1,m) + get(s,t,n-1,m-1);;



    }

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        dp.resize(n+1,vector<int>(m+1,-1));


        return get(s,t,n,m);
        
    }
};
