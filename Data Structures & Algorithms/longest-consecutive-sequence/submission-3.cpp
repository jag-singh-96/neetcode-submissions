class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> set;

        for(auto i: nums){
            set.insert(i);
        }

        int max_len = 1;

        for(auto num: set){

            if(set.find(num-1) == set.end()){

                int x = num;
                int len = 0;

                while(set.find(x) != set.end()){
                    x = x+1;
                    len++;
                }
                max_len = max(len, max_len);

            } 

            
        }

        return max_len;

        
    }
};
