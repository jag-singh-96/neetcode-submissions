class Solution {
public:

    bool isV(vector<int>& weights, int days, int mid){

        int day = 1;

        int sum = 0;

        for(int i = 0; i < weights.size(); i++){

            sum += weights[i];

            if(sum > mid){
                day++;
                sum = weights[i];
                //continue;
            }
        }


        if(day <= days){
            return true;
        }
        
        return false;


    }

    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        int s = *max_element(weights.begin(), weights.end());

        int e = accumulate(weights.begin(), weights.end(), 0);

        int ans = e;

        while(s <= e){
            int mid = (s+e)/2;

            if(isV(weights,days,mid)){
                ans = min(ans,mid);
                e = mid-1;
            }else{
                s = mid+1;
            }

        }

        return ans;
        
    }
};