class Solution {
public:
    #define ll long long 
    bool is_root(ll n){
        ll root=sqrt(n);
        if(root*root==n)return true;
        return false;
    }

    bool judgeSquareSum(int c) {
        ll n=sqrt(c),i;
        if(n*n!=c)n++;
        for(i=0;i<=n;i++){
            ll rem=c- i*i;
            if(rem<0)continue;
            if(is_root(rem))return true;
        }
        return false;
    }
};