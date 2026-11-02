class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();

        stack<int> st;

        st.push(asteroids[0]);


        for(int i = 1; i < n; i++){

            // int t = st.top();

            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }

            if(st.top() > 0 && asteroids[i] < 0 && st.top() + asteroids[i] == 0){
                st.pop();
                continue;
            }

            if(st.top() > 0 && asteroids[i] < 0){

                if(st.top() > abs(asteroids[i])){
                    // i++;
                    continue;
                }
                while(!st.empty() && st.top() > 0 && abs(st.top()) < abs(asteroids[i])){
                    st.pop();
                }
                i--;
            }else{
                st.push(asteroids[i]);
            }

        }

        vector<int> output;

        while(!st.empty()){
            output.insert(output.begin(), st.top());
            // output.push_front(st.top());
            st.pop();
        }

        return output;
        
    }
};