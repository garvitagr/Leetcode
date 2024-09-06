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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>present;
        ListNode* temp=head;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        while(temp!=NULL){
            if(mp[temp->val]==0)present.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* newhead=new ListNode(-1);
        temp=newhead;
        for(int i=0;i<present.size();i++){
            ListNode* newnode=new ListNode(present[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return newhead->next;
    }
};