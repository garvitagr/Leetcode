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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* temp=head;
        ListNode* ins=head;
        int sum=0;
        temp=head->next;

        while(temp!=NULL){
            sum=0;
            while(temp->val != 0){
                sum+=temp->val;
                temp=temp->next;
            }
            temp=temp->next;
            ins->val=sum;
            if(temp!=NULL)ins=ins->next;
        }   
        ins->next=NULL;
        return head;    
    }

};