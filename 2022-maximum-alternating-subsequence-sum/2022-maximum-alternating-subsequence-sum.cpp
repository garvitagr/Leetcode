class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0,ans=0;
        int i,n=nums.size();
        nums.push_back(0);
        bool plus=true;
        for(i=0;i<n;i++){
            if(nums[i]>nums[i+1] and plus){
                sum+=nums[i];
                ans=max(ans,sum);
                plus^=1;
            }
            if(nums[i]<nums[i+1] and !plus){
                sum-=nums[i];
                ans=max(ans,sum);
                plus^=1;
            }
        }
        return ans;
    }
};