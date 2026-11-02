class Solution {
public:
    int maxArea(vector<int>& heights) {


        int n = heights.size();

        int i = 0, j = n-1;

        int water = 0;

        while(i < j){

            int l = min(heights[i],heights[j]);

            water = max(water, (j-i)*l);

            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
           
        }

        return water;
        
    }
};
