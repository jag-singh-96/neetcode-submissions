class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int total_gas = 0;
        int total_cost = 0;

        int g = 0;
        int st = 0;
        for(int i = 0; i < n; i++){

            g += (gas[i] - cost[i]);
            total_gas += gas[i];
            total_cost += cost[i];

            if(g < 0){
                g = 0;
                st = i+1;
            }

        }

        if(total_cost > total_gas) return -1;

        else return st;
        
    }
};
