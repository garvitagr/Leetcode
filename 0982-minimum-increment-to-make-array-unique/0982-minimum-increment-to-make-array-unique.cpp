class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int i,n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(i=1;i<n;i++){
            if(nums[i]<=nums[i-1])ans+=nums[i-1]-nums[i]+1,nums[i]=nums[i-1]+1;
        }
        return ans;
    }
};