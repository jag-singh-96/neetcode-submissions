class Solution {
public:

    bool can(vector<int>& piles, int h, int mid){


        int total = 0;

        for(int i = 0; i < piles.size(); i++){

            int deno = piles[i]/mid;

            total += deno;

            if(piles[i]%mid != 0){
                total += 1;
            }
            // Optional: avoid unnecessary work

            if(total > h) {

                return false;

            }

        }
        return total <= h;

    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();


        int max = *max_element(piles.begin(), piles.end());


        int i = 1, j = max;

        int res = 0;

        while(i <= j){

            int mid = (i+j)/2;

            if(can(piles, h, mid)){
                j = mid-1;
                res = mid;
            }else{
                i = mid+1;
                
            }



        }

        return res;

        
    }
};
