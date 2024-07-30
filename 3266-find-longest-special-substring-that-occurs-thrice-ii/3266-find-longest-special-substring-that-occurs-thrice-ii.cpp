class Solution {
public:
    int find(vector<int>&v){
        int i,n=v.size();
        int low=0,high=v[n-1],mid,ans=0;
        
        while(low<=high){
            mid=(low+high)>>1;
            int times=0;
            for(i=n-1;i>=0;i--){
                if(mid<=v[i])times+=v[i]-mid+1;
            }
            if(times>=3)ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }

    int maximumLength(string s) {
        int ans=0;
        for(char ch='a';ch<='z';ch++){
            int times=0;
            vector<int>v;
            for(int i=0;i<s.size();i++){
                if(s[i]==ch)times++;
                else if(times)v.push_back(times),times=0;
            }
            if(times)v.push_back(times),times=0;
            if(v.empty())continue;
            sort(v.begin(),v.end());
            int maxtimes=find(v);
            ans=max(ans,maxtimes);
        }
        return ans==0?-1:ans;
    }
};