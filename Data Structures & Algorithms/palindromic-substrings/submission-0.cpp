class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,0));

        int count = 0;


        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            count++;
        }

        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n-len+1; i++){
                int j = i + len - 1;

                if(len == 2){
                    if(s[i] == s[j]){
                        count++;
                        dp[i][j] = true;
                    }
                }else if(s[i] == s[j] && dp[i+1][j-1] == true){
                    count++;
                    dp[i][j] = true;
                }
            }
        }

        return count;
        
    }
};
