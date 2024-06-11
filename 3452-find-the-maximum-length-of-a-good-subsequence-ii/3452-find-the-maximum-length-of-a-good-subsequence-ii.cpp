class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int i,j,n=nums.size(),result=0;

        vector<vector<int>>dp(nums.size()+10,vector<int>(k+10,0));
        
        for(j=0;j<=k;j++){
            map<int,int>mp;
            int max_prev_j=0;
            for(i=0;i<nums.size();i++){
                int ans=1;
                ans=max(ans,mp[nums[i]]+1);
                if(j)ans=max(ans,max_prev_j+1);
                mp[nums[i]]=ans;
                if(j)max_prev_j=max(max_prev_j,dp[i][j-1]);
                dp[i][j]=ans;
            }
        }
        for(i=0;i<nums.size();i++){
            result=max(result,dp[i][k]);
        }
        return result;
    }
};