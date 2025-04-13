class Solution {
public:
    int M=1000000007;
    long long power(long long num, long long times){
        if(times==0)return 1;
        if(times&1){

            return (num * power((num * num)%M,times/2 ) ) % M;
        }
        else{
            return (power((num * num)%M,times/2 ) ) % M;
        }
    }
    
    int countGoodNumbers(long long n) {
        long long zero=(n/2)+(n%2),one=n/2;
        return ((power(5,zero))%M*(power(4,one))%M)%M;
    }
};