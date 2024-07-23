class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i,n=nums.size();
        deque<int>dq;
        vector<int>ans;
        for(i=0;i<k;i++){
            while(!dq.empty() and nums[dq.back()]<nums[i])dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(i=k;i<n;i++){
            while(!dq.empty() and nums[dq.back()]<nums[i])dq.pop_back();
            dq.push_back(i);
            while(dq.front()<i-(k-1))dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};