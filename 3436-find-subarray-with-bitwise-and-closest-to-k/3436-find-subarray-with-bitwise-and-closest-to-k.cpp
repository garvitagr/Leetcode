class Solution {
public:
    int cal(map<int,vector<int>>&mp,int ind,int j){
        vector<int>pre=mp[ind-1];
        vector<int>v=mp[j];
        int ans=0,i;
        for(i=0;i<v.size();i++){
            v[i]-=pre[i];
            if(v[i]==0)ans+=(1<<i);
        }
        return ans;
    }

    int minimumDifference(vector<int>& nums, int k) {
        map<int,vector<int>>mp;
        int ans=abs(nums[0]-k),curand=nums[0],i,j,n=nums.size();
        vector<int>bits(32,1);
        mp[-1]=bits;
        for(int i=0;i<nums.size();i++){
            int num=nums[i],ct=0;
            for(int j=0;j<32;j++){
                if(!(num&1))bits[j]++;
                num>>=1;
            }
            mp[i]=bits;
        }
        i=0;j=1;
        
        while(j<n){
            curand&=nums[j];
            ans=min(ans,abs(curand-k));
            while(curand<k and i<j){
                i++;
                curand=cal(mp,i,j);
                ans=min(ans,abs(curand-k));
            }
            j++;
        }
        return ans;
    }
};