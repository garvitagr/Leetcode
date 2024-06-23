class Solution {
public:
    long long helper(int ind,vector<int>&nums,vector<long long>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long pos=nums[ind]+helper(ind+1,nums,dp);
        long long neg=nums[ind];
        if(ind+1<nums.size())neg+=(-nums[ind+1])+helper(ind+2,nums,dp);

        return dp[ind]=max(pos,neg);

    }

    long long maximumTotalCost(vector<int>& nums) {
        vector<long long>dp(nums.size()+10,-1);
        return helper(0,nums,dp);
    }
};