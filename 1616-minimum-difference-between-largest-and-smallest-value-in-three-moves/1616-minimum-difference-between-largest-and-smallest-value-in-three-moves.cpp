class Solution {
public:
    int minDifference(vector<int>& nums) {
        int i,n=nums.size();
        if(n<=3)return 0;
        sort(nums.begin(),nums.end());

        int left0=nums[n-4]-nums[0];
        int left1=nums[n-3]-nums[1];
        int left2=nums[n-2]-nums[2];
        int left3=nums[n-1]-nums[3];

        return min({left0,left1,left2,left3});

    }
};