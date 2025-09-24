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
    ListNode* insertionSortList(ListNode* head) {
        ListNode * ele = head->next;
        while(ele!=NULL){
           ListNode* curr = head, *print = head;

           if(curr->val>ele->val){
                ListNode* prev = head;
                while(prev->next != ele) prev = prev->next;
                prev->next = ele->next;
                ele->next = head;
                head = ele;
                ele = prev->next;
           }else{
            while(curr->next!=ele && curr->next->val<=ele->val){
                curr = curr->next;
            }
            
            if(curr->next->val>ele->val){
            ListNode* ins = ele;
            ListNode* prev = head;
            while(prev->next != ele) prev = prev->next;
            prev->next = ele->next;

            ele = ele->next;            
            ins->next = curr->next;
            curr->next = ins;
            
            }else{
                ele = ele->next;
            }
           }
         
        }
        return head;
    }
};