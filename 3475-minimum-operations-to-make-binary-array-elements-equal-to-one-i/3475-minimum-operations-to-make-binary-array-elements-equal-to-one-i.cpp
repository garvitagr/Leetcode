class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i,n=nums.size();
        int ans=0;
        for(i=0;i<n-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                if(nums[i+1])nums[i+1]=0;
                else nums[i+1]=1;
                if(nums[i+2])nums[i+2]=0;
                else nums[i+2]=1;
                ans++;
            }
        }
        if(nums[n-1]==0 or nums[n-2]==0)return -1;
        return ans;
    }
};