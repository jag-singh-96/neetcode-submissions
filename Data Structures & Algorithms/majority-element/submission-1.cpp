class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int ans = nums[0];

        int count = 1;

        for(auto i : nums){

            if(count == 0){
                ans = i;
            }

            if(ans == i){
                count++;
            }else{
                count--;
            }

            

        }
        return ans;
    }
};