class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long ans=0,ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ct++;
            }else{
                ans+=(ct*ct)-(ct*(ct-1)/2);
                ct=0;
            }
            
        }
        ans+=(ct*ct)-(ct*(ct-1)/2);
        return ans;
    }
};