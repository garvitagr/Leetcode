class Solution {
public:
    double maxprefix(vector<int>&nums){
        vector<double>prefix,suffix;
        double i,n=nums.size(),pro=1,ans;
        if(n==1)return nums[0];
        for(i=0;i<n;i++){
            pro*=nums[i];
            prefix.push_back(pro);
        }
        pro=1;
        for(i=n-1;i>=0;i--){
            pro*=nums[i];
            suffix.push_back(pro);
        }
        ans=max(*max_element(prefix.begin(),prefix.end()), *max_element(suffix.begin(),suffix.end()));
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        int i,n=nums.size(),ans;
        vector<int>v;
        bool add=false;
        ans=maxprefix(nums);
        for(i=0;i<n;i++){
            if(nums[i]!=0)v.push_back(nums[i]),add=true;
            else if(add){
                int temp=maxprefix(v);
                ans=max(ans,temp);
                v.clear();add=false;
            }
        }
        if(v.size()){
            int temp=maxprefix(v);
            ans=max(ans,temp);
        }
        return ans;
    }
};