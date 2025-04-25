class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(auto it:nums)st.insert(it);
        map<int,int>mp;
        int i=0,j=0,ans=0,n=nums.size();
        while(j<n){
            while(j<n and mp.size()!=st.size()){
                mp[nums[j]]++;
                j++;
            }
            while(i<j and mp.size()==st.size()){
                ans+=n-j+1;
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};