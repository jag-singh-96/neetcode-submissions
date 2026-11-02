class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // priority_queue<int,vector<int>,greater<int>> pq;

        priority_queue<int>pq;

        unordered_map<char,int> map;

        for(auto t: tasks){
            map[t]++;
        }

        for(auto m: map){
            pq.push(m.second);
        }

        

        int time = 0;
        while(!pq.empty()){

            vector<int> v;
            for(int i = 0; i <= n ; i++){
                
                if(!pq.empty()){
                    int f = pq.top();
                    f = f-1;
                    if(f != 0){
                        v.push_back(f);
                    }
                    pq.pop();
                    time++;
                }else{
                    if(v.empty()) break;
                    time++;

                }
                
            }
            for(int i = 0; i < v.size(); i++){
               
                    pq.push(v[i]);
             
            }
            
        }

         return time;
        
    }
};
