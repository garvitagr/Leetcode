class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i,n=customers.size(),sum=0,maxi=0;
        vector<int>free(n,0),all(n,0);

        for(i=0;i<n;i++){
            if(!grumpy[i])sum+=customers[i];
            free[i]=sum;
            if(i==0)all[0]=customers[i];
            else all[i]=all[i-1]+customers[i];
        }
        
        for(i=0;i<minutes;i++){
            maxi+=customers[i];
        }
        maxi+=free[n-1]-free[min(n-1,minutes-1)];
        for(i=1;i<=n-minutes;i++){
            int left=free[max(0,i-1)];
            int middle=all[min(n-1,i+minutes-1)]-all[max(0,i-1)];
            int right=free[n-1]-free[min(n-1,i+minutes-1)];
            maxi=max(maxi,left+middle+right);
        }
        return maxi;
    }
};