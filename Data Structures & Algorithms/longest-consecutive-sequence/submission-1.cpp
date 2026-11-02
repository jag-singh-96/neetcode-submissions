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

        for(int i = 0; i < n; i++){

            if(set.find(nums[i]-1) != set.end()){

                int x = nums[i];
                int len = 1;

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
