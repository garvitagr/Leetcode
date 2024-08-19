class Solution {
public:
    int helper(int size,int copy,int n,vector<vector<int>>&dp){
        if(size==n)return 0;
        if(copy>n-size)return INT_MAX;
        if(dp[size][copy]!=-1)return dp[size][copy];
        int ans1=helper(size+copy,copy,n,dp);
        if(ans1!=INT_MAX)ans1+=1;
        int ans2=helper(size+copy,size+copy,n,dp);
        if(ans2!=INT_MAX)ans2+=2;
        return dp[size][copy]=min(ans1,ans2);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<int>>dp(n+1,vector<int>(2*n +1,-1));
        return 1+helper(1,1,n,dp);
    }
};