class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<double, double>> v;

        int n = position.size();

        for(int i = 0; i < n; i++){
            double time = (double)(target-position[i])/speed[i];
            v.push_back({position[i],time});
        }

        sort(v.begin(),v.end());


        double slow = v[n-1].second;
        int count = 1;

        for(int i = n-2; i >= 0; i--){
            
            double t = v[i].second;
            if(t > slow){
                count++;
                slow = t;
            }

        }

        return count;


        
    }
};
