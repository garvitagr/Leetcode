class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans=0,n=nums.size(),i;
        vector<int>need(n),v;
        for(i=0;i<n;i++){
            need[i]=target[i]-nums[i];
        }
        bool pos;
        if(need[0]>=0)pos=true;
        else pos=false;
        ans=abs(need[0]);

        for(i=1;i<n;i++){
            if(need[i]>=0 and pos){
                ans+=(abs(need[i-1])<abs(need[i])?need[i]-need[i-1]:0);
            }
            else if(need[i]<0 and !pos){
                ans+=(abs(need[i-1])<abs(need[i])?abs(need[i])-abs(need[i-1]):0);
            }
            else if(need[i]>=0 and !pos){
                ans+=need[i];
                pos=true;
            }
            else if(need[i]<0 and pos){
                ans+=abs(need[i]);
                pos=false;
            }
        }
        return ans;
    }
};