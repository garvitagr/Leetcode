class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int i=0,j=0,n=nums.size(),ans=1;
        

        while(i<n){
            if(st.empty() and j<n){
                st.insert(nums[j++]);
            }
            while(j<n){
                auto it=st.rbegin();
                int largest=*it;
                auto it1=st.begin();
                int smallest=*it1;
                if(largest-nums[j]<=limit and nums[j]-smallest<=limit){
                    st.insert(nums[j++]);
                    int ele=st.size();
                    ans=max(ans,ele);
                    if(ans==7)cout<<smallest<<" "<<largest<<endl;
                }
                else break;
            }
            auto it=st.find(nums[i++]);
            st.erase(it);
        }
        return ans;
    }
};