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

    ListNode* reverseKGroup(ListNode* head, int k) {
       vector<int> buffer ; 
        ListNode* curr = head;
        while(curr!=NULL){ buffer.push_back(curr->val); curr = curr->next;}

        int i = 0;

        if(k > buffer.size()) return head;

        while(i+k<=buffer.size()){
            reverse(buffer.begin()+i,buffer.begin()+i+k);
            i+=k;
        }
        
        for(auto x : buffer){
            cout<<x<<' ';
        }
        ListNode* ans = new ListNode(buffer[0]);
        curr = ans;
        for(int i=1;i<buffer.size();i++){
            curr ->next = new ListNode(buffer[i]);
            curr = curr -> next;
        }
        return ans;
    }
};