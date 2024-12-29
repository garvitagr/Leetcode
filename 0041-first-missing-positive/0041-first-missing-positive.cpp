class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]<=0)nums[i]=nums.size()+1;
        }
        for(i=0;i<nums.size();i++){
            if(abs(nums[i])>=nums.size()+1)continue;
            int ind=abs(nums[i])-1;
            nums[ind]=-1*abs(nums[ind]);
        }
        for(i=0;i<nums.size();i++){
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
    }
};