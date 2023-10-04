class Solution {
public:
    bool isGood(vector<int>& nums) {
        int i,rest=0,last=0,n=nums.size(),sum=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==n-1){
                sum+=nums[i];
                last++;
            }
            else if(nums[i]<n-1){
                rest++;
                sum+=nums[i];
            }
        }
        if(!(last==2 and rest==n-2))return false;
        if(sum== (n*(n-1))/2 +n-1)return true;
        return false;
    }
};