class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>>ans;
        int steps=0,i=0;
        ans.push_back({rStart,cStart});

        while(ans.size()<rows*cols){
            if(i==0 or i==2)steps++;
            
            for(int count=0;count<steps;count++){
                rStart+=dir[i][0];
                cStart+=dir[i][1];
                
                if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                    ans.push_back({rStart,cStart});
                }
            }
            i=(i+1)%4;
        }
        return ans;
    }
};