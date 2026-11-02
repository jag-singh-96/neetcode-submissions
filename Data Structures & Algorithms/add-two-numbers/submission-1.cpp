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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ptr1 = l1;

        ListNode* ptr2 = l2;

        int sum = 0;

        int carry = 0;


        ListNode* newHead = new ListNode(-1);


        ListNode* ptr = newHead;

        while(ptr1 || ptr2){

            int f = 0, s = 0;

            if(ptr1){
                f = ptr1->val;
            }

            if(ptr2){
                s = ptr2->val;
            }

            sum = f+s+carry;


            if(sum/10 > 0){
                carry = 1;
            }else{
                carry = 0;
            }

            sum = sum%10;


            ListNode*  res = new ListNode(sum);

            ptr->next = res;

            ptr = ptr->next;


            if(ptr1){
                ptr1 = ptr1->next;
            }

            if(ptr2){
                ptr2 = ptr2->next;
            }

        }

        if(carry==1){
            ListNode*  res = new ListNode(1);

            ptr->next = res;
            ptr = ptr->next;

        }

        return newHead->next;

        
    }
};
