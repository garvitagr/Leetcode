class Solution {
public:
    long long minEnd(int n, int x) {
        long long first=x,ind=0;
        long long i,j=0,add,num,ans=0;
        
        add=n-1;
        vector<int>v(100,0);
        while(first){
            v[ind++]=(first&1);
            first>>=1;
        }
        vector<int>addv;
        while(add){
            addv.push_back(add&1);
            add>>=1;
        }
        for(i=0;i<v.size();i++){
            if(j==addv.size())break;
            if(v[i]==1)continue;
            if(v[i]==0 and addv[j]==0)j++;
            else if(v[i]==0 and addv[j]==1){
                v[i]=1;
                j++;
            }
        }
        
        for(i=0;i<v.size();i++){
            if(v[i]==1){
                ans+=pow(2,i);
            }
        }
        
        return ans;
        
    }
};