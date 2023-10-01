class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long i,sum=0,j,ans=INT_MAX,ct,n=nums.size(),ele,ind;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>target){
                sum=INT_MAX;
                break;
            }
        }
        ct=target/sum;
        target%=sum;
        if(target==0)return ct*n;
        vector<int>prefix;
        sum=0;

        for(i=0;i<n;i++)nums.push_back(nums[i]);
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        // cout<<target<<endl;
        for(i=0;i<prefix.size();i++){
            if(prefix[i]<target)continue;
            if(prefix[i]==target){
                ans=min(ans,i+1);
                continue;
            }
            ele=prefix[i]-target;
            // cout<<ele<<" ";
            ind=upper_bound(prefix.begin(),prefix.begin()+i,ele)-prefix.begin();
            cout<<prefix[0]<<" "<<ele<<" ";
            if(ind>0 and prefix[ind-1]==ele)ans=min(ans,i-ind+1);          
            // cout<<ind<<" "<<endl;  
        }
        if(ans==INT_MAX)return -1;
        return ans+(ct*n);   
    }
};