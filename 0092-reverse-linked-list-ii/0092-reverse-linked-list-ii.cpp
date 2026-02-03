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
    if(!head || !head->next) return head;

    ListNode* curr = head->next, *prev = head,*next;

    while(curr != NULL){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head->next = NULL;
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            ListNode* l , *lprev = head,*r=head,*rnext=head,*curr = head;
        while(right--){
            r = rnext;
            rnext = rnext->next;
        }
        r->next = NULL;
        lprev = reverseNode(head);
        ListNode* ans = lprev;
        while(lprev->next != NULL) lprev = lprev->next;
        lprev ->next = rnext;

        return ans;
        }
        ListNode* l , *lprev = head,*r=head,*rnext=head,*curr = head;
        left -= 2;
        while(left > 0 && left--){
            lprev = lprev->next;
        }
        while(right--){
            r = rnext;
            rnext = rnext->next;
        }
        r->next = NULL;
        l = lprev ->next;
        lprev->next = NULL;
        lprev->next = reverseNode(l);
        while(lprev->next != NULL) lprev = lprev->next;
        lprev ->next = rnext;

        return head;
    }
};