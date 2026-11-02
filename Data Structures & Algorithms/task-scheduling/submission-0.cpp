class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if(n == 0) return tasks.size();

        unordered_map<char, int> map;

        priority_queue<int> pq;

        for(auto t: tasks){
            map[t]++;
        }

        for(auto m: map){
            pq.push(m.second);
        }

        int time = 0;

        while(!pq.empty()){

            vector<int> v;

            for(int i = 0; i <= n; i++){
                if(!pq.empty()){
                    int t = pq.top();
                    pq.pop();
                    t--;
                    v.push_back(t);
                }   
            }

            for(int i = 0; i < v.size(); i++){
                if(v[i] > 0){
                     pq.push(v[i]);
                }
               
            }

            if(pq.empty()){
                time += v.size();
            }else{
                time += n+1;
            }
        }

        return time;

        
    }
};
