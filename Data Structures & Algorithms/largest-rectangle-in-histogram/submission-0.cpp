class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        int n = heights.size();

        stack<int> st;

        st.push(0);
        

        int marea = 0;

        for(int i = 1; i < n; i++){

            if(st.empty() || heights[i] >= heights[st.top()]){
                st.push(i);
            }else{

                while(!st.empty() &&  heights[i] < heights[st.top()]){

                    int h = heights[st.top()];
                    st.pop();

                    int w = st.empty() ? i : i - st.top()-1;

                    int area = h*w;

                    marea = max(area,marea);

                }
                i--;

            }

        }
        return marea;
    }
};
