/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void fill(vector<int>&v,ListNode* head){
        if(head==NULL)return;
        v.push_back(head->val);
        fill(v,head->next);
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int>v;
        fill(v,head);
        while(v.size()!=m*n){
            v.push_back(-1);
        }
        vector<vector<int>>ans(m,vector<int>(n));
        int k=0,ct=0;
        while(true){
            if(k==m*n)break;

            //going to the right 
            for(int i=ct;i<n-ct;i++)ans[ct][i]=v[k++];
            
           if(k==m*n)break;

            //going downwards
            for(int i=ct+1;i<m-ct;i++)ans[i][n-1-ct]=v[k++];


            if(k==m*n)break;

            //going left
            for(int i=n-2-ct;i>=ct;i--)ans[m-1-ct][i]=v[k++];

            if(k==m*n)break;

            //going upwards
            for(int i=m-2-ct;i>ct;i--)ans[i][ct]=v[k++];

            ct++;
        }
        return ans;
    }
};