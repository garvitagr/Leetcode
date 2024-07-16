class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int i,n=nums.size(),ct=0;
        vector<int>difarr(n+1,0);
        for(i=0;i<=n-k;i++){
            difarr[i]=(i>0)?difarr[i]+difarr[i-1]:difarr[i];
            if(!((difarr[i]+nums[i])&1)){
                ct++;
                difarr[i]+=1;
                difarr[i+k]+=1;
            }
        }
        for(i=n-k+1;i<n;i++){
            difarr[i]=(i>0)?difarr[i]+difarr[i-1]:difarr[i];
            if(!((difarr[i]+nums[i])&1)){
                return -1;
            }
        }
        return ct;
    }
};