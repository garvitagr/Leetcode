class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i;
        int n=nums.size(),sum=0;
        for(i=0;i<n;i++){
            nums[i]%=k;
        }
        map<int,vector<int>>mp;
        mp[0].emplace_back(-1);
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k and mp[sum%k].size() and mp[sum%k][0]+1!=i)return true;
            mp[(sum)%k].emplace_back(i);
        }
        // mp->5 1 1 3 2
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==0 and nums[i+1]==0)return true;
        }
        return false;
    }
};