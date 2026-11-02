class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> product(n,1);

        int l = 1;

        for(int i = 0; i < n; i++){
            l = l*nums[i];
            product[i] = l;
        }

        int r = 1;

        for(int i = n-1; i > 0 ; i--){
            product[i] = product[i-1]*r;
            r *= nums[i];
        }

        product[0] = r;


        return product;



    }
};
