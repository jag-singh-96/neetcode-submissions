class Solution {
public:

    int get(string text1, string text2, int n, int m){

        if(m==0||n == 0){
            return 0;
        }


        if(text1[n-1] == text2[m-1]){
            return 1+get(text1, text2, n-1, m-1);
        }

        return max(get(text1, text2, n-1, m),get(text1, text2, n, m-1));

    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();


        // return get(text1, text2, n, m);

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }

            }
        }

        return dp[n][m];
        
    }
};
