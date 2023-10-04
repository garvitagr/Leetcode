class Solution {
public:
    int countPrimes(int n) {
        const int N=5*1e6+7;
        vector<int>prime(N,1);
        int i,j,ans=0;

        prime[0]=prime[1]=0;

        for(i=2;i*i<n;i++){
            if(prime[i]){
                for(j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }

        for(i=0;i<n;i++){
            if(prime[i])ans++;
        }
        return ans;
    }
};