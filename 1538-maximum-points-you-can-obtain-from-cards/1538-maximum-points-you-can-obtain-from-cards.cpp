class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int i,n=v.size(),ans=0,sum=0,j=0;
        for(i=n-k;i<n;i++)sum+=v[i];
        ans=max(ans,sum);
        for(i=n-k;i<n;i++){
            sum-=v[i];
            sum+=v[j++];
            ans=max(ans,sum);
        }
        return ans;
    }   
};