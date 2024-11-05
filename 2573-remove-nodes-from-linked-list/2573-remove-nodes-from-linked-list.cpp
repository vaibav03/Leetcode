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

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; 
}

   ListNode* removeNodes(ListNode* head) {
    ListNode* curr = reverse(head);
    int maxVal = curr->val;

      ListNode* temp = curr; 
      
    while (curr && curr->next) {
        if (curr->next->val >= maxVal) {
            maxVal = curr->next->val;
            curr = curr->next;
        } else {
            curr->next = curr->next->next;
        }
    }

    return reverse(temp); 
}

};