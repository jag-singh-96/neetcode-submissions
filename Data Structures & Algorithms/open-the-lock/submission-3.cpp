class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> set;

        for(auto d: deadends){
            set.insert(d);
        }


        queue<pair<string, int>> q;
        unordered_set<string> v;

        q.push({"0000",0});
        v.insert("0000");

        if(set.find("0000") != set.end()) return -1;


        while(!q.empty()){

            string node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node == target) return level;


            for(int i = 0; i < node.length(); i++){
                
                char temp = node[i];
                
                node[i] = temp == '9' ? '0' : temp + 1;

                if(set.find(node) == set.end() && v.find(node) == v.end()){
                    q.push({node,level+1});
                    v.insert(node);
                }


                node[i] = temp == '0' ? '9' : temp - 1;

                if(set.find(node) == set.end() && v.find(node) == v.end()){
                    q.push({node,level+1});
                    v.insert(node);
                }

                node[i] = temp;

            }

        }

        return -1;

        
    }
};