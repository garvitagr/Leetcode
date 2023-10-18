class Solution {
public:

    int profit(vector<int>&prices,int &mini,int &ans,int i){
        if(i==prices.size())return ans;

        ans=max(ans,prices[i]-mini);
        mini=min(prices[i],mini);
        return profit(prices,mini,ans,i+1);
    }

    int maxProfit(vector<int>& prices) {
        int mini=prices[0],ans=0;
        return profit(prices,mini,ans,1);
    }
};