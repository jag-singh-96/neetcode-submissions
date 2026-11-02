class Solution {
public:

    int mo(vector<int>& people, int limit){

        int l = 0, r = people.size()-1;

        int ans = 0;

         while(l <= r){

            if(people[l] + people[r] <= limit){
                ans++;
                l++;
                r--;
            }else if(people[r] <= limit){
                r--;
                ans++;
            }else{
                l++;
                ans++;
            }

        }

        return ans;


    }

    int numRescueBoats(vector<int>& people, int limit) {

        int n = people.size();

        int m = *max_element(people.begin(), people.end());

        vector<int> count(m+1,0);

        for(auto p: people){
            count[p]++;
        }

        int ans = 0;

       
        int idx = 0;
        for(int val = 0 ; val <= m; val++){

            while(count[val] > 0){
                people[idx++] = val;
                count[val]--;
            }

        }

        ans = mo(people, limit);

        

        return ans;
        
    }
};