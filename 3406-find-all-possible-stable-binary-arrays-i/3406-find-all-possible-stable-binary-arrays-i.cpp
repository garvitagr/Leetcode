class Solution {
public:
    int mod=1000000007;
    int helper(int zero,int one,int chance,int limit,vector<vector<vector<int>>>&dp){
        if(zero==0 and one==0)return 1;
        if(dp[chance][zero][one]!=-1)return dp[chance][zero][one];
        int ans=0;
        if(chance==0){
            for(int i=1;i<=min(zero,limit);i++){
                ans+=helper(zero-i,one,1,limit,dp);
                ans%=mod;
            }
        }
        else{
            for(int i=1;i<=min(one,limit);i++){
                ans+=helper(zero,one-i,0,limit,dp);
                ans%=mod;
            }
        }
        return dp[chance][zero][one]=ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(zero+1,vector<int>(one+1,-1)));
        return (helper(zero,one,0,limit,dp)+helper(zero,one,1,limit,dp))%mod;
    }
};