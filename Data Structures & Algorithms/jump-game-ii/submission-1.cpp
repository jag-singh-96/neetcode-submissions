class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int jump = 0;

        int max_r = 0;

        int prev = 0;

        if (n == 1) return 0;

        for(int i = 0; i < n; i++){
            if(max_r < i) return -1;

            max_r = max(max_r, nums[i]+i);


            if(prev == i){
                prev = max_r;
                jump++;
                if(max_r >= n-1) return jump;
            }




        }

        return -1;



        
    }
};
