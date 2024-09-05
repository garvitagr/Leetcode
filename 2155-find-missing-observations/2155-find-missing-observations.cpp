class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(auto it:rolls)sum+=it;
        int req=mean*(n+m);
        req-=sum;
        sum=0;
        vector<int>ans;
        for(int i=1;i<=n;i++){
            int rem=n-i;
            bool find=false;
            if(rem==0 and sum+1>req)return {};
            for(int j=1;j<=6;j++){
                if((rem*6) +(sum+j)>=req){
                    sum+=j;
                    ans.push_back(j);
                    find=true;
                    break;
                }
            }
            if(!find)return {};
        }
        return ans;
    }
};