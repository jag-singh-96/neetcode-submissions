class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int temp1 = 0,count1 = 0;

        int temp2 = 0, count2 = 0;

        int target = n/3;

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(temp1 == nums[i]){
                count1++;
            }else if(temp2 == nums[i]){
                count2++;
            }else if(count1 == 0){
                temp1 = nums[i];
                count1++;
            }else if(count2 == 0){
                temp2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        

        count1 = 0;
        count2 = 0;


        for(auto num: nums){
            if(temp1 == num){
                count1++;
            }
            if(temp2 == num){
                count2++;
            }
        }

        if(count1 > target){
            ans.push_back(temp1);
        }

        if(count2 > target){
            ans.push_back(temp2);
        }

        return ans;
    }
};