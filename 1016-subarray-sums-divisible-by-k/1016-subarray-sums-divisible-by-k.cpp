class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]++;
        int sum=0,i,ans=0,n=nums.size();
        
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=0){
                ans+=mp[(sum%k)];
                mp[sum%k]++;
            }
            else{
                int temp=-sum;
                temp%=k;
                temp*=-1;
                if(temp<0)temp+=k;
                ans+=mp[temp];
                mp[temp]++;
            }
       }
        return ans;
    }
};