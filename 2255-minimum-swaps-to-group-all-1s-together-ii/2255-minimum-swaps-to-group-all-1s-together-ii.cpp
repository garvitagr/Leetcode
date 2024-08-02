class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int i,ones=0,ct=0,ans;
        for(auto it:nums){
            if(it==1)ones++;
        }
        for(i=0;i<ones;i++){
            if(nums[i]==0)ct++;
        }
        ans=ct;
        for(i=1;i<nums.size();i++){
            if(nums[i-1]==0)ct--;
            if(nums[(i+ones-1)%nums.size()]==0)ct++;
            ans=min(ans,ct);
        }
        return ans;
    }
};