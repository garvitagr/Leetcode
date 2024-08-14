class Solution {
public:
    int find(int x,vector<int>&nums,int k){
        int ct=0;
        for(int i=0;i<nums.size();i++){
            int rem=x+nums[i];
            int ind=upper_bound(nums.begin(),nums.end(),rem)-nums.begin();
            ct+=ind-i-1;
        }
        return ct;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int low=0,high=1,ans;
        sort(nums.begin(),nums.end());
        while(find(high,nums,k)<k)high*=2;
        while(low<=high){
            int mid=low+ ((high-low)>>1);
            if(find(mid,nums,k)>=k){
                ans=mid;high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};