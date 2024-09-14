class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ct=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)ct++;
            else ans=max(ans,ct),ct=0;
        }
        ans=max(ans,ct);
        return ans;
    }
};