int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        vector<int>::iterator it;
        for(int i = 0; i < nums.size(); i++){
            it = lower_bound(v.begin(), v.end(), nums[i]);
            if(v.end() == it) v.push_back(nums[i]);
            else v[it-v.begin()] = nums[i];
        }
        return v.size();
    }
