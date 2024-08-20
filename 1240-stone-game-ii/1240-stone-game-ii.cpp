class Solution {
public:
    int helper(int ind,vector<int>&piles,int M,int chance,vector<vector<vector<int>>>&dp){
        if(ind==piles.size())return 0;
        int stones=0;
        if(dp[ind][M][chance]!=-1)return dp[ind][M][chance];
        if(chance==1){
            int ans=INT_MIN;
            for(int i=ind;i<(piles.size()) and i<ind+M;i++){
                int taken=i-ind+1;
                stones+=piles[i];
                int temp=stones+helper(i+1,piles,max(M,2*taken),2,dp);
                ans=max(ans,temp);
            }
            return dp[ind][M][chance]=ans;
        }
        else{
            int ans=INT_MAX;
            for(int i=ind;i<(piles.size()) and i<ind+M;i++){
                int taken=i-ind+1;
                int temp=helper(i+1,piles,max(M,2*taken),1,dp);
                ans=min(ans,temp);
            }
            return dp[ind][M][chance]=ans;
        }
        
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2*n+2,vector<int>(3,-1)));
        return helper(0,piles,2,1,dp);
    }
};