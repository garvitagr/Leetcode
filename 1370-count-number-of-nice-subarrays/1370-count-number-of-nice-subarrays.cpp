class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>v;
        v.emplace_back(-1);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)v.emplace_back(i);
        }
        v.emplace_back(nums.size());
        for(int i=k;i<v.size()-1;i++){
            int left=v[i-k+1]-v[i-k];
            int right=v[i+1]-v[i];
            ans+=left*right;
        }
        return ans;
    }
};