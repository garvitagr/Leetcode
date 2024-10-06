class Solution {
public:

    int find(string n){
        int ans=0;
        for(int i=0;i<n.size();i++){
            if(n[i]&1)ans+=(1<<i);
        }
        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        string s1,s2,s3;
        while(nums[0]){
            if(nums[0]&1)s1+='1';
            else s1+='0';
            nums[0]>>=1;
        }
        while(nums[1]){
            if(nums[1]&1)s2+='1';
            else s2+='0';
            nums[1]>>=1;
        }
        while(nums[2]){
            if(nums[2]&1)s3+='1';
            else s3+='0';
            nums[2]>>=1;
        }
        int res=0;
        string temp=s1+s2+s3;
        
        int num=find(temp);

        res=max(res,num);
        temp=s1+s3+s2;
        num=find(temp);

        res=max(res,num);
        temp=s2+s1+s3;
        num=find(temp);

        res=max(res,num);
        temp=s2+s3+s1;
        num=find(temp);

        res=max(res,num);
        temp=s3+s1+s2;
        num=find(temp);

        res=max(res,num);
        temp=s3+s2+s1;
        num=find(temp);

        res=max(res,num);
        
        return res;
    }
};