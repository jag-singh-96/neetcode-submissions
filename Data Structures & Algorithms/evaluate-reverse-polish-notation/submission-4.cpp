class Solution {
public:

    bool isOp(string st){
        if(st == "+"){
            return true;
        }
        if(st == "*"){
            return true;
        }
        if(st == "-"){
            return true;
        }
        if(st == "/"){
            return true;
        }

        return false;
    }

    int doOp(string st, int a, int b){
        if(st == "+"){
            return a+b;
        }
        if(st == "*"){
            return a*b;
        }
        if(st == "-"){
            return a-b;
        }
        if(st == "/"){
            return a/b;
        }

        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();

        stack<int> st;


        for(int i = 0; i < n; i++){

            if(isOp(tokens[i])){

                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = doOp(tokens[i],a,b);
                st.push(res);

            }else{
                st.push(stoi(tokens[i]));
            }

        }

        return st.top();

    }
};
