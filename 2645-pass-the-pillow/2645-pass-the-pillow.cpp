class Solution {
public:
    int passThePillow(int n, int time) {
        int i,ball=1;
        bool right=true;
        while(time--){
            if(right)ball++;
            else ball--;
            if(ball==n)right=false;
            if(ball==1)right=true;
        }
        return ball;
    }
};