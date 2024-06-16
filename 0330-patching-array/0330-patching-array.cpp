class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long i=0,ans=0,sum=0;
        sort(nums.begin(),nums.end());
        nums.push_back(n);

        for(i=0;i<nums.size();i++){

            while(sum+1<nums[i]){
                if(sum>=n)break;
                sum+=sum+1;
                ans++;
            }
            sum+=nums[i];
            
            // cout<<i<<" "<<ans<<endl;
        }
        // cout<<sum<<endl;

        return ans;        
    }
};