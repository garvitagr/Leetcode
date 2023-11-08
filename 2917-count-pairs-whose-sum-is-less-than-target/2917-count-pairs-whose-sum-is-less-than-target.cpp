class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,ans=0;
        while(i<j){
            cout<<i<<" "<<j<<" ";
            if(nums[i]+nums[j]<target){
                ans+=(j-i);
                i++;
            }
            else j--;
            cout<<ans<<endl;
        }
        return ans;
    }
};