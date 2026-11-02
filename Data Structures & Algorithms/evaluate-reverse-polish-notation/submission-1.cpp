class Solution {
public:

    bool isV(string str){

        if(str == "+"  || str == "-" || str == "*" || str == "/"){
            return true;
        }

        return false;

    }

    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();

        stack<int> st;

        for(int i = 0; i < n; i++){

            if(!isV(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{

                int f = st.top();
                st.pop();

                int s = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(f+s);
                }


                if(tokens[i] == "-"){
                    st.push(s-f);
                }

                if(tokens[i] == "*"){
                    st.push(s*f);
                }

                if(tokens[i] == "/"){
                    st.push(s/f);
                }

            }
        }

        return st.top();
        
    }
};
