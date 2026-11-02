class Solution {
public:

    vector<int> tSort(unordered_map<int, vector<int>> adj, vector<int> present){

        queue<int> q;

        vector<int> in(26,0);


        for(int i = 0;i < 26;i++){
            if(present[i] == true){
                for(auto x: adj[i]){
                    in[x]++;
                }
            }
        }


        for(int i = 0; i < 26; i++){
            if(present[i] && in[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;

        while(!q.empty()){

            int node = q.front();
            q.pop();


            res.push_back(node);

            for(auto x: adj[node]){
                in[x]--;
                if(in[x] == 0){
                    q.push(x);
                }
            }
        }

        for(int i = 0; i < 26; i++){
            if(present[i] && in[i] > 0) return {};
        }


        return res;



    }

    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        unordered_map<int, vector<int>> adj;

        vector<int> present(26,false);


        for(auto w: words){
            for(char c: w){
                present[c-'a'] = true;
            }
        }
        
        for(int i = 1; i < n; i++){
            int m = min(words[i].length(), words[i-1].length());
            bool found = false;
            for(int j = 0; j < m; j++){
                if(words[i][j] != words[i-1][j]){
                    found = true;
                    adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                    break;
                }
            }
            if(!found && words[i].length() < words[i-1].length()){
                return "";
            }
        }


        vector<int> topo = tSort(adj,present);

        int sz = topo.size();
        if(sz == 0) return "";

        string str = "";
        for(int i = 0; i < topo.size(); i++){
            str += (topo[i] + 'a');
        } 
        

        return str;
    }
};
