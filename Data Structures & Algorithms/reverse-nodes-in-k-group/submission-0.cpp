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

        if(head == NULL || head->next == NULL) return head;

        int len = k;

        ListNode* curr = head;

        while(curr && len){
            curr = curr->next;
            len--;
        }

        if(len > 0) return head;

        ListNode* ptr = head;
        ListNode* prev = NULL;

        ListNode* next = NULL;

        int count = 0;

        while(ptr && count < k){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            count++;
        }

        head->next = reverseKGroup(ptr,k);
        return prev;
        
    }
};
