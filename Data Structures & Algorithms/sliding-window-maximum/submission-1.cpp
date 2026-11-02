class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        // multiset<int> set;

        // for(int i = 0; i < k; i++){
        //     set.insert(nums[i]);
        // }

        // vector<int> ans;

        // ans.push_back(*set.rbegin());

        // for(int i = k; i < n; i++){

        //     set.erase(set.find(nums[i-k]));
        //     set.insert(nums[i]);
        //     ans.push_back(*set.rbegin());

        // }

        // return ans;


        deque<int> dq;

        vector<int> ans;


        for(int i = 0; i < n; i++){

            if(i >= k && (i-k) == dq.front()){
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }


            

        }

        return ans;

        
    }
};
