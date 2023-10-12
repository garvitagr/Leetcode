class Solution {
public:

    int bs(vector<int>&nums,int target,int s,int e){
        if(s>e)return -1;
       int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
            return bs(nums,target,s,e);
        }
        else {
            s=mid+1;
            return bs(nums,target,s,e);
        }   
    }

    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
};