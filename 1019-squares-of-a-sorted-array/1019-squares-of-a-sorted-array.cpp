class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int i=0,j=0,n=nums.size();
        if(n==1)return {nums[0]*nums[0]};
        for(i=0;i<n-1;i++){
            if(abs(nums[i])>=abs(nums[i+1]))j=i+1;
            else break;
        }
        ans.push_back(nums[j]*nums[j]);
        i=j-1;j=j+1;
        while(i>=0 and j<n){
            if(nums[i]*nums[i]<=nums[j]*nums[j])ans.push_back(nums[i]*nums[i]),i--;
            else ans.push_back(nums[j]*nums[j]),j++;
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]),i--;;
        }
        while(j<n){
            ans.push_back(nums[j]*nums[j]),j++;
        }
        return ans;
    }
};