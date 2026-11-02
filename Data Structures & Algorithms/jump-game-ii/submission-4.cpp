class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int jump = 0;

        int maxReach = 0;

        int prev = 0;

        if(n == 1) return 0;

        if(n == 0) return -1;


        for(int i = 0;i < n; i++){

            if(maxReach < i ) return -1;

            maxReach = max(maxReach, i +nums[i]);

           

            if(prev == i){
                 cout<<maxReach<<" "<<endl;
                prev = maxReach;
                jump++;

                if(maxReach >= n-1) return jump;
            }

        }

        return -1;

        
    }
};
