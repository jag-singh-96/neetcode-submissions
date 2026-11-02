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
        

        for(int i = 0; i < n && sptr != NULL; i++){
            sptr = sptr->next;
        }


        ListNode* fptr = dummy;

        while(sptr->next != NULL){
            fptr = fptr->next;
            sptr = sptr->next;
        }

        // return fptr;

        fptr->next = fptr->next->next;
        // fptr->next->next = NULL;


        return dummy->next;

        
    }
};
