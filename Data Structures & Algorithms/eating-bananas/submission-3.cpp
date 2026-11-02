class Solution {
public:

    int can(int mid, vector<int>& piles, int h){

        int n = piles.size();
        int total_hours = 0;

        for(int i = 0; i < n; i++){
            
            int p = piles[i];

            total_hours += p / mid;

            p = p % mid;

            if(p % mid != 0){
                total_hours += 1;
            }
            
        }

        if(total_hours <= h) return true;

        return false;

    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int l = 1, r = *max_element(piles.begin(),piles.end());

        int ans = r;
        
        while(l <= r){

            int mid = (l + r)/2;

            if(can(mid, piles, h)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }

        }

        return ans;
        
    }
};
