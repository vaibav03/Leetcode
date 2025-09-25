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
    class cmp{
        public:
        bool operator() (ListNode* a,ListNode* b){
            return (a->val > b->val) ? true : false;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0),*curr = ans;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(ListNode* node : lists){
            if(node!=NULL) pq.push(node);
        }
        while(!pq.empty()){
            auto node = pq.top();
            cout<<node->val<<" ";
            pq.pop();
            ans->next = node;
            ans = ans->next;
            if(node->next) pq.push(node->next);
        }

        return curr->next;
    }
};