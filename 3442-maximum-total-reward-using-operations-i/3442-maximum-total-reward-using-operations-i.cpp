class Solution {
public:
    int helper(vector<int>&v,int ind,int cursum,vector<vector<int>>&dp){
        if(ind==v.size())return cursum;
        if(dp[ind][cursum]!=-1)return dp[ind][cursum];
        int take=0,nottake=0;
        if(v[ind]>cursum){
            take=helper(v,ind+1,cursum+v[ind],dp);
        }
        nottake=helper(v,ind+1,cursum,dp);

        return dp[ind][cursum]=max(take,nottake);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        vector<vector<int>>dp(rewardValues.size()+10,vector<int>(10000+10,0));
        // return helper(rewardValues,0,0,dp);

        int i,j;
        
        for(i=rewardValues.size();i>=0;i--){
            for(j=5000;j>=0;j--){
                if(i==rewardValues.size())dp[i][j]=j;
                else{
                    int take=0,nottake=0;
                    if(rewardValues[i]>j){
                        take=dp[i+1][j+rewardValues[i]];
                    }
                    nottake=dp[i+1][j];

                    dp[i][j]=max(take,nottake);
                }
            }
        }

        return dp[0][0];
    }
};