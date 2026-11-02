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

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* sptr = dummy;
        ListNode* fptr = dummy;

        for(int i = 0; i < n && fptr != NULL; i++){
            fptr = fptr->next;
        }

        while(fptr->next != NULL){
            sptr= sptr->next;
            fptr = fptr->next;
        }
        
        ListNode* ptr = sptr->next;
        sptr->next = sptr->next->next;
        delete(ptr);
    
        return dummy->next;

        
    }
};
