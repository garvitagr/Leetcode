class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int i,j,ans=0;
        vector<int>v;
        for(i=0;i<n;i++){
            int sum=0;
            for(j=i;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        for(i=left-1;i<=right-1;i++)ans+=v[i],ans%=1000000007;
        return ans;
    }
};