class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        if(n&1)return false;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                int val=arr[i]*-1;
                int times=val/k;
                arr[i]+=(times+1)*k;
            }
            mp[arr[i]%k]++;
        }
        for(auto it:mp){
            if((it.first==0)){
                if(it.second&1)return false;
                continue;
            }
            else{
                int fir=it.first;
                int sec=k-fir;
                if(mp[fir]!=mp[sec]){
                    return false;
                }
            }
        }
        return true;
    }
};