class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        multiset<int> set;


        for(int i = 0; i < k; i++){
            set.insert(nums[i]);
        }
        vector<int> ans;

        ans.push_back(*set.rbegin());

        for(int i = k; i < n; i++){

            set.erase(set.find(nums[i-k]));

            set.insert(nums[i]);

            ans.push_back(*set.rbegin());

        }

        return ans;
        
    }
};
