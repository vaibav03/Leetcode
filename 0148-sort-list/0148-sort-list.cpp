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
    ListNode* findmiddle(ListNode* head,ListNode* high){
        ListNode* slow = head, *fast = head,*lim = high->next;
        while(fast!=lim && fast->next!=lim && fast->next->next!=lim){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* low, ListNode* high){
        ListNode* mid = findmiddle(low,high);
        cout<<low->val<<" "<<mid->val<<" "<<high->val<<endl;
        if(low == high) return new ListNode(low->val);

        ListNode* ll1 = mergeSort(low,mid);
        ListNode* ll2 = (mid->next) ? mergeSort(mid->next,high) : NULL;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(ll1 && ll2){
            if(ll1->val<ll2->val){
                dummy->next = new ListNode(ll1->val);
                ll1 = ll1->next;
            }else{
               dummy->next = new ListNode(ll2->val);
                ll2 = ll2->next; 
            }
            dummy = dummy->next;
        }
        dummy->next = (ll1) ? ll1 : ll2;
        return curr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head ==NULL) return NULL;

        ListNode* final = head;
        while(final->next!=NULL) final = final->next;

        return mergeSort(head,final);
 
    }
};