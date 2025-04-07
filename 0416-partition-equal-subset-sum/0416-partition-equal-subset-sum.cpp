class Solution {
public:
   bool part(vector<int>&nums,int half,int sum2,int ind,int n,vector<vector<int>>&dp){
    if(ind>=n){
        if(sum2!=half)return false;
        else return true;
    }
    
    if(dp[sum2][ind]!=-1)return dp[sum2][ind];
    int take=part(nums,half,sum2-nums[ind],ind+1,n,dp);
    int nottake=part(nums,half,sum2,ind+1,n,dp);
    // if(sum2==half){return true;}
    return dp[sum2][ind]=take || nottake;
   }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum2=0;
        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }
        vector<vector<int>>dp(sum2+10,vector<int>(n+10,-1));
        if(sum2%2!=0)return false;
        int half=sum2/2;
        return part(nums,half,sum2,0,n,dp);
    }
};