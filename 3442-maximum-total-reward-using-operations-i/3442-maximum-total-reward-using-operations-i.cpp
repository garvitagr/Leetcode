class Solution {
public:
    // unordered_map<int,unordered_map<int,int>>dp;
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
        // int sum=0,i;
        // for(i=0;i<rewardValues.size();i++)sum+=rewardValues[i];
        vector<vector<int>>dp(rewardValues.size()+10,vector<int>(10000+10,-1));
        return helper(rewardValues,0,0,dp);
    }
};