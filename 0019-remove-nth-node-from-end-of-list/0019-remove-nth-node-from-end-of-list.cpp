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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        int len  = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
                if (n == len) {
            ListNode* newHead = head->next;

            return newHead;
        }

        curr = head;
        len--;
        while(len>n){
            cout<<curr->val<<" ";
            curr = curr->next;
            len--;
        }
        if(curr->next != NULL)
        curr->next = curr->next->next;
        else curr->next = NULL;

        return head;
    }
};