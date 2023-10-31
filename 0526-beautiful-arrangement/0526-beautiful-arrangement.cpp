class Solution {
public:

    void put(int &ans,int n,vector<int> &v,int num){
        if(num>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if( (v[i]==0) and ((i%num==0) or (num%i==0))){
                v[i]=num;
                put(ans,n,v,num+1);
                v[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        int ans=0;
        vector<int>v(n+1,0);
        put(ans,n,v,1);
        return ans;
    }
};