class Solution {
public:


    int find(vector<int> &nums){
        int n = nums.size();

        int i = 0, j = n-1;

        int res = 0;
        while(i < j){

            int mid = (i+j)/2;
            if(nums[mid] > nums[j]){
                i = mid+1;
            }else{
                j = mid;
                res = nums[mid];
            }

        }
        return nums[i];

    }
    
    int findMin(vector<int> &nums) {

        int pivot = find(nums);

        return pivot;
        
    }
};
