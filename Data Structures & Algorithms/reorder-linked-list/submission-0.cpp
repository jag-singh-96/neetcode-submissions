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

    ListNode* getMid(ListNode* head){

        ListNode* sptr = head;
        ListNode* fptr = head;

        while(fptr && fptr->next){
            sptr = sptr->next;
            fptr = fptr->next->next;
        }

        return sptr;

    }

    ListNode* getRev(ListNode* newHead){

        if(newHead == NULL || newHead->next == NULL) return newHead;


        ListNode* ptr = getRev(newHead->next);

        newHead->next->next = newHead;
        newHead->next = NULL;

        return ptr;


    }

    void reorderList(ListNode* head) {

        ListNode* ptr = getMid(head);

        ListNode* newHead = ptr->next;

        ptr->next = NULL;

        ListNode* rev = getRev(newHead);
        

        ListNode* res = new ListNode(-1);

        ptr = res;

        while(head || rev){
            
            if(head != NULL){
                ptr->next = head;
                ptr = ptr->next;
                head = head->next;
            }
            if(rev != NULL){
                ptr->next = rev;
                rev = rev->next;
                ptr = ptr->next;
            }

        }

        head = res->next;

        
    }
};
