class Solution {
public:
    int helper(int i,int j,string &s,vector<vector<int>>&dp){
        if(i==j)return 1;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<j;k++){
            int left=helper(i,k,s,dp);
            int right=helper(k+1,j,s,dp);
            ans=min({ans,left+right});
        }
        if(s[i]==s[j])ans--;
        return dp[i][j]=ans;
    }

    int strangePrinter(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return helper(0,s.size()-1,s,dp);
    }
};