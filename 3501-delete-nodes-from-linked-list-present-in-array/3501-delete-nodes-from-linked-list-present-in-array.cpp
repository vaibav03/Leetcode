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
        unordered_map<int,int> M;
        for(int i=0;i<nums.size();i++){
            M[nums[i]]++;
        }
        ListNode* prev = head,*curr = head;

        while(M[prev->val] >= 1){
            cout<<prev->val<<endl;
            curr = prev->next;
            prev = NULL;
            prev = curr;
        }
        while(curr->next!=NULL){
            if(M[curr->next->val] >= 1){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return prev;
    }
};