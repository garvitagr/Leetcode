class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int ct=0;
            if(i-k<0)ct++;
            else if(nums[i-k]<nums[i])ct++;
            if(i+k>=nums.size())ct++;
            else if(nums[i]>nums[i+k])ct++;
            if(ct==2)sum+=nums[i];
        }
        return sum;
    }
};