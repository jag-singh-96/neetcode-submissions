class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        int max_r = 0;

        for(int i = 0; i < n; i++){
            
            max_r = max(max_r, nums[i]+i);

            if(max_r <=  i && max_r != n-1) return false;

        }

        return true;
        
    }
};
