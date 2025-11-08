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
    int getDecimalValue(ListNode* head) {
        int ans{},powe{};
        ListNode* curr = head;
        while(curr!=NULL){
            powe++;
            curr = curr->next;
        }
        curr = head;
        powe--;
        cout<<powe<<endl;
        while(curr!=NULL){
            ans += (pow(2,powe)* curr->val);
            powe--;
            curr = curr->next;
        }
        return ans;
    }
};