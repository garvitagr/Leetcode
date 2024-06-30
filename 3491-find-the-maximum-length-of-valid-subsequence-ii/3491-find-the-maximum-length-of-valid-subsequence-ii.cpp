class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        map<int,vector<int>>occurences;
        int i,n=nums.size(),j,ans=2;
        vector<vector<int>>dp(n+10,vector<int>(n+10,0));
        for(i=0;i<n;i++){
            nums[i]%=k;
            occurences[nums[i]].push_back(i);
        }
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){

                if(occurences[nums[i]][0]>=j){
                    dp[i][j]=2;
                }
                else{
                    auto ind=lower_bound(occurences[nums[i]].begin(),occurences[nums[i]].end(),j);
                    if(*ind>=j)ind--;
                    dp[i][j]=1+dp[j][*ind];

                }
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;

    }
};