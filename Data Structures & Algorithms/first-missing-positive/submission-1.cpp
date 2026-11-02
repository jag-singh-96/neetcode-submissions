class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        int ans = 1;

        for(int i = 0; i < n; i++){

            if(nums[i] < 0 || nums[i] > n) continue;

            int ele = nums[i];

            int chair = ele - 1;

            // if(i == nums[i] - 1) continue;


            if(nums[i] != nums[chair]){
                swap(nums[i], nums[chair]);
                // cout<<i<<endl;
                i--;
                // cout<<i<<endl;
            }
        }
        

        for(int i = 0; i < n; i++){

            if(i != nums[i] - 1) return i+1;
        }

        return n+1;
    }
};