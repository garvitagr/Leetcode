class Solution {
public:
    int findComplement(int num) {
        int i,ans=0;
        for(i=0;num;i++){
            if(!(num&1))ans+=(1<<i);
            num>>=1;
        }
        return ans;
    }
};