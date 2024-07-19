class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long front=0,back=0,ans=0,n=nums.size();
        multiset<int>st;
        while(front<n){
            while(!st.empty()){
                int mxm=*st.rbegin();
                int mnm=*st.begin();
                if(!(mxm>nums[front]+2 or mnm<nums[front]-2))break;
                int val=nums[back++];
                auto it=st.find(val);
                st.erase(it);
            }
            st.insert(nums[front++]);
            ans+=st.size();
        }
        return ans;
    }
};