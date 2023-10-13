class Solution {
public:

    bool f(int tar,long long x){
        if(x==tar)return true;
        else if(x>tar)return false;
        return f(tar,x*2);
    }

    bool isPowerOfTwo(int n) {
        return f(n,1);
    }
};