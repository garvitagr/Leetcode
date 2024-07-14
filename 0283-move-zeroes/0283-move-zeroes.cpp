class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,n=nums.size(),j=0;
        for(i=0;i<n;i++){
            if(nums[i]!=0)nums[j++]=nums[i];
        }
        for(j;j<n;j++)nums[j]=0;
    }
};