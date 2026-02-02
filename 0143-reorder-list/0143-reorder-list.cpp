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
    ListNode* reverseNode(ListNode* head){
        ListNode* curr = head->next , *prev = head;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = NULL;
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return ;
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow -> next;
        slow -> next = NULL;
        ListNode* ll2 = reverseNode(mid);
        ListNode* ll1 = head;

        while(ll1!=NULL && ll2!=NULL){
            //cout<<ll1->val<<" "<<ll2->val<<endl;
            ListNode* store1 = ll1->next,*store2 = ll2->next; 
            cout<<ll1->val<<" "<<ll2->val<<" "<<store1<<" "<<store2<<endl;
            ll1->next = ll2;
            if(store1)
            ll2->next = store1;

            ll1 = store1;
            ll2 = store2;
        }
    }
};