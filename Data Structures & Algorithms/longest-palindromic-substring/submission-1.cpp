class Solution {
public:

    vector<int> even(string s, int i){

        int l = i, r = i+1;
        int start = i, end = i;
        while(l >= 0 && r < s.length()){
            if(s[l] == s[r]){
                start = l;
                end = r;
                l--,r++;
               
            }else{
                break;
            }
        }
        return {start,end};
    }


    vector<int> odd(string s, int i){

        int l = i, r = i;
        int start = i, end = i;
        while(l >= 0 && r < s.length()){
            if(s[l] == s[r]){
                start = l;
                end = r;
                l--,r++;
            }else{
                break;
            }
        }
        return {start,end};
    }

    string longestPalindrome(string s) {

        int n = s.length();

        string ans = "";
        int len = 0;
        vector<int> l;

        for(int i = 0; i < n; i++){
            l = odd(s,i);
            int length = (l[1] - l[0] + 1);
                cout<<l[0]<<" "<<l[1]<<endl;
            if(len < length){
                ans = s.substr(l[0],length);
                len = length;
            }
        }
  
        for(int i = 0; i < n; i++){
            l = even(s,i);
            int length = (l[1] - l[0]+1);
            
            if(len < length){
                ans = s.substr(l[0],length);
                len = length;
            }
        }
        

        return ans;
        
    }
};
