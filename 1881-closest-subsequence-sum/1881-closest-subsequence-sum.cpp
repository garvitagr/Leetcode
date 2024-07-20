class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size(),i,j,ans=INT_MAX;
        vector<int>arr1,arr2;
        int size1=n-n/2;
        int size2=n-size1;
        
        for(int i=0;i<(1<<size1);i++){
            int sum=0;
            for(int j=0;j<size1;j++){
                if( i&(1<<j) ){
                    sum+=nums[j];
                }
            }
            arr1.push_back(sum);
        }
        for(int i=0;i<(1<<size2);i++){
            int sum=0;
            for(int j=0;j<size2;j++){
                if( i&(1<<j) ){
                    sum+=nums[size1+j];
                }
            }
            arr2.push_back(sum);
        }
        sort(arr2.begin(),arr2.end());
        for(i=0;i<arr1.size();i++){
            int val=arr1[i];
            int rem=goal-val;
            int ind=lower_bound(arr2.begin(),arr2.end(),rem)-arr2.begin();
            if(ind==arr2.size())ind--;
            ans=min(ans,abs(val+arr2[ind]-goal));
            ind--;
            if(ind<0)continue;
            ans=min(ans,abs(val+arr2[ind]-goal));
        }
        return ans;
    }
};