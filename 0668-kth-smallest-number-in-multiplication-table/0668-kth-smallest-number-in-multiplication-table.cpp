class Solution {
public:
    bool check(int m,int n,int k,int mid){
        int ct=0;
        for(int i=1;i<=m;i++){
            ct+=min(n,(mid)/i);
        }
        if(ct>=k)return true;
        else return false;
    }

    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n,ans=m*n;
        while(low<=high){
            int mid=(low+high)>>1;
            if(check(m,n,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};