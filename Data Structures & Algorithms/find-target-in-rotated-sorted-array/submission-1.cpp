class Solution {
public:

    int findP(vector<int>& nums){

        int n = nums.size();


        int i = 0, j = n-1;


        while(i < j){

            int mid = (i+j)/2;

            // cout<<mid<<endl;

            if(mid-1 >= 0 && mid+1 < n && (nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])){
                return mid;
            }

            if(mid+1 < n && nums[mid+1] < nums[mid]){
                return mid+1;
            }

            if(mid-1 > 0 && nums[mid-1] > nums[mid]){
                return mid;
            }


            if(nums[i] > nums[mid]){
                j = mid-1;
            }else{
                i = mid+1;
            }

        }

        return -1;


    }

    int binarySearch(vector<int>& nums,int i, int j, int target){

        
        while(i <= j){

            int mid = (i+j)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                
                j = mid-1;
            }else{
                i = mid+1;
                // cout<<i<<"-- "<<j<<endl;
            }

            

        }
        return -1;

    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = findP(nums);

        if(pivot == -1){
            pivot = 0;
        }

        if(target == nums[pivot]) return pivot;

        if(pivot == 0){
            return binarySearch(nums,0,n-1,target);
        }

        if(nums[0] > target){
            return binarySearch(nums,pivot,n-1,target);
        }

        return binarySearch(nums,0,pivot-1,target);
        
    }
};
