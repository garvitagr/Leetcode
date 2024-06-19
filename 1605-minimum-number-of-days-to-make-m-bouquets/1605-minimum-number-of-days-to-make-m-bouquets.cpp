class Solution {
public:
       int nofb(vector<int> &bloom,int m,int mid,int k)
        {   
            int i,val=0,ct=0;
            for(i=0;i<bloom.size();i++){
                if(bloom[i]<=mid)val++;
                if(val==k){
                    ct++;val=0;
                }
                else if(bloom[i]>mid){
                    val=0;
                }
            }

            return ct;
        }
    int minDays(vector<int>& bloom, int m, int k) {
 
        long long n=bloom.size();
        long long M=m,K=k;
        long long check=M*K;
        if (n<check){
            return -1;
        }
        int low=*min_element(bloom.begin(),bloom.end());
        int high=*max_element(bloom.begin(),bloom.end());
        int ans;
        int mid;
        while(low<=high){
            int mid = (low + high)/2;
            int cons=nofb(bloom,m,mid,k);
            if (cons>=m){
                ans=mid;
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }
        return ans;
    }
};