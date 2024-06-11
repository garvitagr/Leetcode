class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        const int N=1e5;
        bitset<N>dp,mask;
        dp[0]=1;
        int i,n=rewardValues.size(),j=0;
        sort(rewardValues.begin(),rewardValues.end());

        for(i=0;i<n;i++){
            while(j<rewardValues[i]){
                mask[j++]=1;
            }
            dp=(dp | ((dp&mask)<<rewardValues[i]));
        }

        for(i=N-1;i>=0;i--){
            if(dp[i])return i;
        }
        return 0;
    }
};