class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ct=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+2]==nums[i+1]/2 and !((nums[i+1])&1))ct++;
        }
        return ct;
    }
    };