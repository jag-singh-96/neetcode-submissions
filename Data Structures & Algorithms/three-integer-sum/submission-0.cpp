class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < n; i++){

            int l = i+1, r = n-1;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while(l < r){

                int f = nums[i];
                int s = nums[l];
                int t = nums[r];

                if(f+s+t == 0){
                    res.push_back({f,s,t});


                    while(l > 0 && nums[l] == nums[l+1]){
                    l++;
                    }
                    while(r > 0 && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if(f+s+t > 0){
                    r--;
                }else{
                    l++;
                }

                


            }

        }

        return res;
        
    }
};
