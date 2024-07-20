class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2,i,j,tot=0,tar,ans=INT_MAX;
        vector<vector<int>>left(n +1),right(n +1);
        for(int i:nums)tot+=i;
        tar=tot/2;
        for(i=0;i<(1<<n);i++){
            int sum1=0,sum2=0,ct=0;
            for(j=0;j<n;j++){
                if(i&(1<<j)){
                    sum1+=nums[j];
                    sum2+=nums[j+n];
                    ct++;
                }
            }
            left[ct].push_back(sum1);
            right[ct].push_back(sum2);
        }
        for(i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }
        
        for(i=0;i<=n;i++){
            for(auto leftsum:left[i]){
                int rightsum=tar-leftsum;
                
                auto &v=right[n-i];
                
                int ind=lower_bound(v.begin(),v.end(),rightsum)-v.begin();
                if(ind==v.size())ind--;
                int firstarraysum=leftsum+v[ind];
                int secondarraysum=tot-firstarraysum;
                ans=min(ans,abs(firstarraysum-secondarraysum));
                ind--;
                if(ind<0)continue;
                firstarraysum=leftsum+v[ind];
                secondarraysum=tot-firstarraysum;
                ans=min(ans,abs(firstarraysum-secondarraysum));
            }
        }

        return ans;
    }
};