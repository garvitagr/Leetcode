class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        map<int,vector<int>>occ;
        int i,n=nums.size(),j;
        int ans=2;
        for(i=0;i<n;i++)occ[nums[i]].push_back(i);
        vector<vector<int>>dp(n+10,vector<int>(n+10,-1));
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                int dif=nums[i]-nums[j];
                int prev=nums[j]-dif;
                if(occ.find(prev)!=occ.end() and occ[prev][0]<j){
                    auto ind=lower_bound(occ[prev].begin(),occ[prev].end(),j);
                    ind--;
                    dp[i][j]=1+dp[j][*ind];
                }
                else{
                    dp[i][j]=2;
                }
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};